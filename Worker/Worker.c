#include <string.h>
#include "..\LinkedList\LinkedList.h"
#include "..\MathFunctions\MathFunctions.h"
#include "Worker.h"

// Text description of the actions.
const char actionDescription[NUMBER_OF_ACTIONS][ACTION_DESCRIPTION_SIZE] = 
{
	"To do his work well!\t\t\t\t|\n|\t\t\t\t\t\t\t|\n",
	"To take %.2flv from the cash register!\t\t|\n|\t\t\t\t\t\t\t|\n",
	"To return %.2flv to the cash register!\t\t|\n|\t\t\t\t\t\t\t|\n"
};

void WorkerChooseAction(worker_t **worker)
{
		// If worker has no money.
		if ((*worker)->money == 0.0f)
		{
			// Choose action between first two actions.
			(*worker)->action = rand() % (NUMBER_OF_ACTIONS - 1);

			if ((*worker)->action == TAKE_MONEY)
			{
				// Generate how much money will the worker take.
				(*worker)->money = GenerateRandomFloat(1, 2);
			}
		}
		else // If worker has money.
		{
			(*worker)->action = RETURN_MONEY;
		}

		(*worker)->isActionDone = 0;

		// Get action description.
		(void)strcpy((*worker)->actionDescription, actionDescription[(*worker)->action]);
}

void WorkerAddSpacesToName(char *name)
{
	const unsigned char length = (unsigned char)strlen(name); // Saves the length of the name at the beggining.

	// Check if name length is NOT the max possible length.
	if (length < (NAME_SIZE - 1))
	{
		unsigned char i = 0;
		for (i = 0; i < (NAME_SIZE - length) - 1; i++)
		{
			(void)strcat(name, " ");
		}
	}
}

void WorkerGoToGetBack(worker_t **worker, float *cashRegisterMoney, node_t ***listOfWorkers)
{
	// Takes money.
	*cashRegisterMoney -= (*worker)->money;

	(*worker)->isActionDone = 1;
	(*worker)->isWaited = 0;

	// Go back to the end of the list.
	ListAddNodeLast(listOfWorkers, **worker);
	ListDeleteFirstNode(listOfWorkers);
}

void WorkerTakeMoney(worker_t **worker, float *cashRegisterMoney, node_t ***listOfWaitingWorkers, node_t ***listOfWorkers)
{
	// Worker takes money.
	if ((*listOfWaitingWorkers == NULL) && ((*cashRegisterMoney - (*worker)->money) >= 0.0f))
	{
		WorkerGoToGetBack(worker, cashRegisterMoney, listOfWorkers);
	}
	else // Worker goes to wait. 
	{
		// If worker has waited till now. Takes money.
		if ((*worker)->isWaited == 1)
		{
			WorkerGoToGetBack(worker, cashRegisterMoney, listOfWorkers);
		}
		else // If worker has NOT waited till now. Goes to wait.
		{
			(*worker)->isWaited = 1;

			ListAddNodeLast(listOfWaitingWorkers, **worker);
			ListDeleteFirstNode(listOfWorkers);
		}
	}
}

void WorkerReturnMoney(worker_t *worker, float *cashRegisterMoney, node_t ***listOfWorkers)
{
	*cashRegisterMoney += worker->money;

	worker->money = 0.0f;

	worker->isActionDone = 1;

	ListAddNodeLast(listOfWorkers, *worker);
	ListDeleteFirstNode(listOfWorkers);
}

void WorkerDoAction(worker_t **worker, float *cashRegisterMoney, node_t ***listOfWaitingWorkers, node_t ***listOfWorkers)
{
	// Checks which action to do.
	switch ((*worker)->action)
	{
	case WORK_PROPERLY:
		(*worker)->isActionDone = 1;

		ListAddNodeLast(listOfWorkers, **worker);
		ListDeleteFirstNode(listOfWorkers);
		break;
	case TAKE_MONEY:
		WorkerTakeMoney(worker, cashRegisterMoney, listOfWaitingWorkers, listOfWorkers);
		break;
	case RETURN_MONEY:
		WorkerReturnMoney(*worker, cashRegisterMoney, listOfWorkers);
		break;
	}
}
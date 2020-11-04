#include <stdio.h>
#include <Windows.h>
#include"MainFunctions.h"

void PrintWorkersList(const node_t * const list)
{
	node_t *currentNode = list;
	char format[FORMAT_SIZE] = { 0 }; // Format of output.
	size_t index = 0; // Node's index.

					  // If current node is NOT empry.
	while (currentNode != NULL)
	{
		(void)strcpy(format, "| %d\t\t\t\t\t\t\t|\n| name = %s |\n| age = %d\t\t\t\t\t\t|\n| Goal = ");
		(void)strcat(format, currentNode->data.actionDescription);

		// Needed to make output better.
		WorkerAddSpacesToName(currentNode->data.name);

		// Set output color.
		if (currentNode->data.action == TAKE_MONEY)
		{
			(void)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);// 12 = light red.
		}
		else if (currentNode->data.action == RETURN_MONEY)
		{
			(void)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);// 10 = light green.
		}

		// If worker is going to take or return money from cash register.
		if (currentNode->data.action != WORK_PROPERLY)
		{
			(void)printf(format, index, currentNode->data.name, currentNode->data.age, currentNode->data.money);
		}
		else // If worker is going to just work.
		{
			(void)printf(format, index, currentNode->data.name, currentNode->data.age);
		}

		(void)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		index++;
		currentNode = currentNode->next;
	}

	free(currentNode);
}

void InitWorkersAtTheBeginning(const node_t * const listOfWorkers, worker_t *worker)
{
	const size_t size = ListGetSize(listOfWorkers);

	size_t i = 0;
	for (i = 0; i < size; i++)
	{
		worker = ListSearchByIndex(listOfWorkers, i);

		WorkerChooseAction(&worker);
	}
}

void Output(node_t *listOfWorkers, node_t *listOfWaitingWorkers, const float money)
{
	(void)puts("---------------------------------------------------------");
	(void)printf("|\tmoney in cash register = %.2f\t\t\t|\n", money);
	(void)puts("---------------------------------------------------------");
	(void)puts("|\t\t\t Order of workers!\t\t|");
	(void)puts("---------------------------------------------------------");

	PrintWorkersList(listOfWorkers);

	(void)puts("---------------------------------------------------------");
	(void)puts("|\t\t Workers waiting for money!\t\t|");
	(void)puts("---------------------------------------------------------");

	PrintWorkersList(listOfWaitingWorkers);

	(void)puts("---------------------------------------------------------");

	(void)system("pause");
	(void)system("cls");
}

void ProgramLoop(node_t *listOfWorkers, node_t *listOfWaitingWorkers, cashRegister_t cashRegister, worker_t *worker)
{
	while (1)
	{
		Output(listOfWorkers, listOfWaitingWorkers, cashRegister.money);

		if (listOfWaitingWorkers != NULL)
		{
			worker = ListSearchByIndex(listOfWaitingWorkers, 0);

			// If in cash reguster are enought money, first waiting worker does actoin.
			if (cashRegister.money > worker->money)
			{
				ListAddNodeFirst(&listOfWorkers, *worker);
				ListDeleteFirstNode(&listOfWaitingWorkers);

				Output(listOfWorkers, listOfWaitingWorkers, cashRegister.money);
			}
		}

		// First worker do action.
		worker = ListSearchByIndex(listOfWorkers, 0);
		WorkerDoAction(&worker, &cashRegister.money, &listOfWaitingWorkers, &listOfWorkers);

		// Last worker choose aciton.
		worker = ListSearchByIndex(listOfWorkers, ListGetSize(listOfWorkers) - 1);

		// Check if worker has done hisaction before choosing another.
		if (worker->isActionDone == 1)
		{
			WorkerChooseAction(&worker);
		}
	}
}
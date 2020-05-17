#include <stdio.h>
#include"MainFunctions.h"

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

	ListPrint(listOfWorkers);

	(void)puts("---------------------------------------------------------");
	(void)puts("|\t\t Workers waiting for money!\t\t|");
	(void)puts("---------------------------------------------------------");

	ListPrint(listOfWaitingWorkers);

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
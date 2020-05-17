#include <stdio.h>
#include <time.h>
#include "MainFunctions\MainFunctions.h"

int main(int argc, char **argv)
{
	node_t *listOfWorkers = NULL;// All workers in the shop.
	node_t *listOfWaitingWorkers = NULL;// Workers which wait to get money from the cash register. 
	cashRegister_t cashRegister = { MAX_MONEY_IN_CASH_REGISTER };
	worker_t *worker = NULL;

	srand(time(NULL));

	// Check if the arguments are needed number.
	if (argc > 1)
	{
		OpenFile(&listOfWorkers, argv);

		InitWorkersAtTheBeginning(listOfWorkers, worker);

		ProgramLoop(listOfWorkers, listOfWaitingWorkers, cashRegister, worker);

		worker = NULL;//This is needed to free worker corectly.
		free(worker);

		ListDelete(&listOfWorkers);
		ListDelete(&listOfWaitingWorkers);
	}
	else
	{
		(void)puts("Erro: Not enough number of arguments!");
	}

	return 0;
}
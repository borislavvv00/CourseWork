#pragma once

#include "..\File\File.h"
#include "..\MathFunctions\MathFunctions.h"

/* Initialize workers' data at the beginning.
*
* arguments: const node_t * const listOfWorkers
*			  worker_t *worker
*
* return type: void
*/
void InitWorkersAtTheBeginning(const node_t * const listOfWorkers, worker_t *worker);

/* Program output.
*
* arguments: node_t *listOfWorkers
*			  node_t *listOfWaitingWorkers
*			  const float money
*
* return type: void
*/
void Output(node_t *listOfWorkers, node_t *listOfWaitingWorkers, const float money);

/* Program loop.
*
* arguments: node_t *listOfWorkers
*			  node_t *listOfWaitingWorkers
*			  cashRegister_t cashRegister
*			  worker_t *worker
*
* return type: void
*/
void ProgramLoop(node_t *listOfWorkers, node_t *listOfWaitingWorkers, cashRegister_t cashRegister, worker_t *worker);
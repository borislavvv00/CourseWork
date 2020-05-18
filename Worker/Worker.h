#pragma once

#include <stdlib.h>
#include "..\CashRegister\CashRegister.h"

#define NAME_SIZE ((size_t) 47) 
#define ACTION_DESCRIPTION_SIZE ((size_t) 100)
#define NUMBER_OF_ACTIONS ((unsigned char) 3)

extern const char actionDescription[NUMBER_OF_ACTIONS][ACTION_DESCRIPTION_SIZE];

// Worker actions.
typedef enum
{
	WORK_PROPERLY = 0, TAKE_MONEY, RETURN_MONEY, NONE
}action_e;

// Worker at the shop.
typedef struct
{
	char name[NAME_SIZE];
	unsigned char isActionDone; // 0(false), 1(true)
	unsigned char age;
	unsigned char isWaited; // Used to indentify if worker has waited till now. 0(false), 1(true)
	action_e action;// The taken action.
	float money;// Money that are in the worker.
	char actionDescription[ACTION_DESCRIPTION_SIZE]; // Description of the taken action.
}worker_t;

// Node of worker's data.
typedef struct Node
{
	worker_t data;
	struct Node *next;
}node_t;

/* Generates action of the worker.
 *
 * arguments: worker_t **worker
 *
 * return type: void
 */
void WorkerChooseAction(worker_t **worker);

/* Adds spaces to worker's name.
 *
 * arguments: char *name
 *
 * return type: void
 */
void WorkerAddSpacesToName(char *name);

/* Goes back to the end of the list.
 *
 * arguments: worker_t **worker
 *			  float *cashRegisterMoney
 *			  node_t ***listOfWorkers
 *
 * return type: void
 */
void WorkerGoToGetBack(worker_t **worker, float *cashRegisterMoney, node_t ***listOfWorkers);

/* Takes money from cash register.
 *
 * arguments: worker_t **worker
 *			  float *cashRegisterMoney
 *			  node_t ***listOfWaitingWorkers
 *			  node_t ***listOfWorkers
 *
 * return type: void
 */
void WorkerTakeMoney(worker_t **worker, float *cashRegisterMoney, node_t ***listOfWaitingWorkers, node_t ***listOfWorkers);

/* Returns money to the cash register.
 *
 * arguments: worker_t *worker
 *			  float *cashRegisterMoney
 *			  node_t ***listOfWorkers
 * 
 * return type: void
 */
void WorkerReturnMoney(worker_t *worker, float *cashRegisterMoney, node_t ***listOfWorkers);

/* Worker do the given action.
 *
 * arguments: worker_t **worker
 *			  float *cashRegisterMoney
 *			  node_t ***listOfWaitingWorkers
 *			  node_t ***listOfWorkers
 *
 * return type: void
 */
void WorkerDoAction(worker_t **worker, float *cashRegisterMoney, node_t ***listOfWaitingWorkers, node_t ***listOfWorkers);
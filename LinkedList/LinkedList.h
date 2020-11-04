#pragma once

#include "..\Worker\Worker.h"

#define FORMAT_SIZE 120

/* Add node first in the list.
*
* arguments: node_t **list
*			 const worker_t worker
*
* return type: void
*/
void ListAddNodeFirst(node_t **list, const worker_t worker);

/* Deletes all list's nodes.
*
* arguments: node_t **list
*
* return type: void
*/
void ListDelete(node_t **list);

/* Search for given node by index and then returns that node.
*
* arguments: const node_t *list
*			 const size_t index
*
* return type: node_t*
*/
node_t *ListSearchByIndex(const node_t *list, const size_t index);

/* Gets the number of elements of the list.
*
* arguments: const node_t * const list
*
* return type: void
*/
size_t ListGetSize(const node_t * const list);

/* Add node last in the list.
 *
 * arguments: node_t **list
 *			  const worker_t worker
 *
 * return type: void
 */
void ListAddNodeLast(node_t **list, const worker_t worker);

/* Delete first node of the list.
 *
 * arguments: node_t **list
 *
 * return type: void
 */
void ListDeleteFirstNode(node_t **list);
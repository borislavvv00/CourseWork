#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "LinkedList.h"

void ListAddNodeFirst(node_t **list, const worker_t worker)
{
	node_t *newNode = (node_t*)malloc(sizeof(node_t));

	// Check if the newNode is empty.
	if (newNode != NULL)
	{
		newNode->data = worker;
		newNode->next = *list;

		*list = newNode;
	}
	else
	{
		(void)puts("Error: Memory when ListAddElementFirst was not alocated correctrly.");
	}

	newNode = NULL;// This is needed otherwise newNode won't be free correctly.
	free(newNode);
}

void ListDelete(node_t **list)
{
	node_t *currentNode = list;
	node_t *nextNode = NULL;

	// If current node is NOT empry.
	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}

	*list = NULL;

	free(currentNode);
	free(nextNode);
}

node_t *ListSearchByIndex(const node_t *list, const size_t index)
{
	size_t count = 0;// Count list's nodes.

	// Search for node with given index.
	while (count != index)
	{
		// If list is NOT empty.
		if (list != NULL)
		{
			list = list->next;
			count++;
		}
		else // If list is empty.
		{
			break;
		}
	}

	// If list's nodes are less then the given index.
	if (count != index)
	{
		return NULL;
	}
	else // If the list has node with the given index.
	{
		return list;
	}
}

size_t ListGetSize(const node_t * const list)
{
	node_t *temp = list;
	size_t count = 0;// Count list's nodes.

	// Counts list nodes.
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}

void ListAddNodeLast(node_t **list, const worker_t worker)
{
	node_t *temp = *list;
	node_t *newNode = (node_t*)malloc(sizeof(node_t));

	// Check if newNode is empty.
	if (newNode != NULL)
	{
		newNode->data = worker;
		newNode->next = NULL;

		// If the list is NOT empty.
		if (temp != NULL)
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			temp->next = newNode;
		}
		else // If the list is empty.
		{
			*list = newNode;
		}
	}
	else
	{
		(void)puts("Error: Memory when ListAddNodeLast was not alocated correctrly.");
	}

	temp = NULL;
	free(temp);

	newNode = NULL;
	free(newNode);
}

void ListDeleteFirstNode(node_t **list)
{
	// Check if list is empty.
	if (list != NULL)
	{
		node_t *firstNode = list;

		// If the node is NOT last.
		if ((*list)->next != NULL)
		{
			**list = *(*list)->next;
		}
		else // If the node is last.
		{
			*list = NULL;
		}

		firstNode = NULL;
		free(firstNode);
	}
}
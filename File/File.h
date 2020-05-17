#pragma once

#include "..\LinkedList\LinkedList.h"

/* Opens file.
 * 
 * arguments:  node_t **list
 *			   const char **argv
 *
 * return type: void
 */
void OpenFile(node_t **list, const char **argv);

/* Read data from text file.
 *
 * arguments: node_t **list
 *			  const FILE *file
 *
 * return type: void
 */
void ReadFromTextFile(node_t **list, const FILE *file);

/* Check if the given file is text. If it is text returns 1(true) else returns 0(false).
 *
 * arguments: char *fileName
 *
 * return type: unsigned char
 */
unsigned char IsGivenFileText(char *fileName);
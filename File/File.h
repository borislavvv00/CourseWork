#pragma once

#include "..\LinkedList\LinkedList.h"

#define AGE_SIZE 2
#define STRING_BETWEEN_AGE_AND_NAME_SIZE 3

/* Opens file.
 * 
 * arguments:  node_t **list
 *			   const char **argv
 *
 * return type: void
 */
void OpenTextFile(node_t **list, const char **argv);

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
 * arguments: const char *fileName
 *
 * return type: unsigned char
 */
unsigned char IsGivenFileText(const char *fileName);

/* Check if the given charecter is in the given range.
 *
 * arguments: const char sign
 *			  const char lowerSign
 *			  const char higherSign
 *
 * return type: void
 */
void CheckSign(const char sign, const char lowerSign, const char higherSign);

/* Replace a charecter with a given charecter.
*
* arguments: char *string
*			 const char searchedSign
*			 const char replacingSign
*
* return type: void
*/
void ReplaceCharInString(char *string, const char searchedSign, const char replacingSign);
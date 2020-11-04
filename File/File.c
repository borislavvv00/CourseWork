#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "File.h"

void CheckSign(const char sign, const char lowerSign, const char higherSign)
{
	if (sign < lowerSign || sign > higherSign)
	{
		(void)puts("Error: Wrong format!\nThe right foramt is: age | name ");
		exit(1);
	}
}

void ReplaceCharInString(char *string, const char searchedSign, const char replacingSign)
{
	while (*string != '\0')
	{
		if (*string == searchedSign)
		{
			*string = replacingSign;
		}

		string++;
	}
}

void ReadFromTextFile(node_t **list, const FILE *file)
{
	worker_t temp = { 0 }; // Temporary stores the data from file.
	char fileLine[NAME_SIZE + AGE_SIZE + STRING_BETWEEN_AGE_AND_NAME_SIZE] = { 0 }; // Stores current line of the file.

	// Reads data from text file.
	while(fgets(fileLine, (NAME_SIZE + AGE_SIZE + STRING_BETWEEN_AGE_AND_NAME_SIZE), file) != NULL)
	{
		CheckSign(fileLine[0], '1', '9');// First charecter of the age.
		CheckSign(fileLine[1], '0', '9');// Second charecter of the age.
		CheckSign(fileLine[2], ' ', ' ');// Between age and the vertikal line we have space.
		CheckSign(fileLine[3], '|', '|');// Age and the name are split by a vertikal line.
		CheckSign(fileLine[4], ' ', ' ');// Between name and the vertikal line we have space.

		ReplaceCharInString(&fileLine, '\n', ' ');// Removes new line, because in the worker's name we don't need new line.

		temp.age = ((int)fileLine[0] - 48) * 10 + ((int)fileLine[1] - 48);

		(void)strcpy(temp.name, fileLine + 5);

		ListAddNodeFirst(list, temp);
	}
}

unsigned char IsGivenFileText(const char *fileName)
{
	char *fileNameExtention = (char*)malloc(sizeof(char) * 3);

	if (fileNameExtention != NULL)
	{
		// Takes the extention of the file.
		(void)strcpy(fileNameExtention, &fileName[strlen(fileName) - 3]);

		// If file is text.
		if (strcmp(fileNameExtention, "txt") == 0)
		{
			fileNameExtention = NULL;// This is needed to free fileNameExtention memory correct.
			free(fileNameExtention);
			return 1;
		}
		else // If file is NOT text.
		{
			fileNameExtention = NULL;// This is needed to free fileNameExtention memory correct.
			free(fileNameExtention);
			return 0;
		}
	}
	else
	{
		(void)puts("Error: Memory when IsGivenFileText was not alocated correctrly.");
		exit(1);
	}
}

void OpenTextFile(node_t **list, const char **argv)
{
	// Check if the file is text.
	if (IsGivenFileText(argv[1]) == 1)
	{
		FILE *file = fopen(argv[1], "r");

		// Check if file pointer is empty.
		if (file != NULL)
		{
			ReadFromTextFile(list, file);

			(void)fclose(file);
		}
		else
		{
			(void)puts("Erro: File cannot be opened!");
			exit(1);
		}
	}
	else
	{
		(void)puts("Erro: File is not text type!");
		exit(1);
	}
}
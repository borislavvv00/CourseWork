#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "File.h"

void ReadFromTextFile(node_t **list, const FILE *file)
{
	worker_t temp = { 0 }; // Temporary stores the data from file.

	// Reads data from text file.
	while (fscanf(file, "%d | %s\n", &temp.age, temp.name) != EOF)
	{
		ListAddNodeFirst(list, temp);
	}
}

unsigned char IsGivenFileText(char *fileName)
{
	char *fileNameExtention = fileName;

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

void OpenFile(node_t **list, const char **argv)
{
	FILE *file = fopen(argv[1], "r");

	// Check if file pointer is empty.
	if (file != NULL)
	{
		// Check if the file is text.
		if (IsGivenFileText(argv[1]) == 1)
		{
			ReadFromTextFile(list, file);
		}
		else
		{
			(void)puts("Erro: File is not text type!");
		}

		(void)fclose(file);
	}
	else
	{
		(void)puts("Erro: File cannot be opened!");
	}
}
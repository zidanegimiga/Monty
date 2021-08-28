#include "monte.h"
/**
 * readlines - reads the lines from a file and stores them in an array
 * @filepointer: pointer to the file to be read
 * Return: pointer to the array of strings
 */

char **readlines(FILE *filepointer)
{
	char *file_line;
	char **all_lines = NULL;
	size_t *bufsize = NULL;
	int i = 0;

	if (!filepointer)
	{
		perror("Error: Can't open file <file>");
		exit(EXIT_FAILURE);
	}
/* read the lines from opcode file into an array of lines */
	while (getline(&file_line, bufsize, filepointer) != -1)
	{
		all_lines[i] = file_line;
		i++;
	}

	all_lines[i + 1] = '\0';
	return (all_lines);
}

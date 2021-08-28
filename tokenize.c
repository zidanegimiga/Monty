#include "monte.h"

/**
 * tokenizer - splits line to strings
 * @line: pointer to sentence
 * Return: pointer to an array of tokens
 */

char **tokenizer(char *line)
{
	int j = 0;
	char *token;
	char **tokens = malloc(sizeof(char) * 1024);

	if (!tokens)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
/* get first token*/
	token = strtok(line, " ");
	while (!token)
	{
		tokens[j] = token;
		j++;
		token = strtok(NULL, " ");
	}

	tokens[j] = NULL;
	return (tokens);
}
/**
 * get_op - gets from line what opcode is given
 * @tokens: pointer to an array or line chunks
 * Return: pointer to the opcode
 */
char *get_op(char **tokens)
{
	char *opcode;
	int op_index = 0;
/*
 * since strtok converts delimeter to a null byte,
 * traverses the tokens and stop
 * when an char that's not a null byte of encountered
 */
	while (tokens[op_index] == '\0')
	{
		op_index++;
	}
	opcode = tokens[op_index];
	return (opcode);
}

/**
 * op_arg - gets the argument passed to the opcode
 * @tokens: chunks of the line after tokenizing
 * Return: integer to be oprated on
 */
int op_arg(char **tokens)
{
	char *opcode = get_op(tokens);
	int j, i = 0;
	int op_argument;


	while (tokens[i] != opcode)
		i++;

	j = i + 1;

	while (tokens[j] == '\0')
		j++;

	op_argument = atoi(tokens[j]);

	return (op_argument);
}

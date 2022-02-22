#include "monty.h"

/**
 * handles calls to push opcode
 * @headptr: pointer to funcs_t head node
 * @tmp: pointer to funcs_t node
 * @command: pointer to char array containing required opcode
 * @endptr: to be used in strtol function call
 * @arg: pointer to argument to push command
 * @line: pointer to char array containing string read from file
 * @fp: pointer to open file stream
 *
 * Return: no return value (void)
 */
void push_handler(funcs_t *headptr, funcs_t *tmp, char *command, char *endptr,
		  char *arg, char *line, FILE *fp)
{
	unsigned int int_arg = 0;

	if (arg)
		int_arg = strtol(arg, &endptr, 10);
	if ((arg == NULL || endptr == arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n",
			ourdata.line_number);
		free_stuff(fp, headptr, line);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(command, "push") == 0)
	{
		tmp->n->f(&(ourdata.head), int_arg);
		tmp = headptr;
	}
}

/**
 * workhorse - calls required function based on opcode read
 * @line: pointer to string read in from file
 * @headptr: pointer to head node of funcs_t list
 * @fp: pointer to open file stream
 *
 * Return: no return value (void)
 */
void workhorse(FILE *fp, funcs_t *headptr, char *line)
{
	char *endptr = NULL, *command = NULL, *arg = NULL;
	unsigned int status = 0;
	funcs_t *tmp = headptr;

	ourdata.line_number++;
	command = strtok(line, " ");
	arg = strchr(command, '\n');
	if (arg)
		*arg = 0;
	arg = strtok(NULL, " ");
	while (tmp != NULL)
	{
		get_funcs(&(ourdata.head), ourdata.line_number);
/*		if (strcmp(command, tmp->n->opcode) == 0)
		{
			if (strcmp(command, "push") == 0)
			{
				push_handler(headptr, tmp, command, endptr, arg,
					     line, fp);
				status = 1;
				break;
			}
			tmp->n->f(&(ourdata.head), ourdata.line_number);
			tmp = headptr, status = 1;
			if (ourdata.line_number == INT_MAX)
			{
				free_stuff(fp, headptr, line);
				exit(EXIT_FAILURE);
			}
			break;
		}
		tmp =  tmp->next;
*/
	}
	if (status == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
ourdata.line_number, command);
		free_stuff(fp, headptr, line), exit(EXIT_FAILURE);
	}
	status = 0;
	line = NULL;
}

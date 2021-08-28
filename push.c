#include "monte.h"
/**
 * push - adds an elements to the stack(or queue)
 * @line_number: line to interpret
 * @stack: pointer to stack to add element
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *line;
	char **linechunks, **all_lines;
	int i = 0, j, n;
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *stack;

	all_lines = readlines(fileptr);
	line = all_lines[line_number - 1];
	linechunks = tokenizer(line);
	for (; strcmp(linechunks[i], "push") != 0; i++)
		;
	j = i + 1;
	for (; linechunks[j] == '\0'; j++)
		;
	n = atoi(linechunks[j]);
	if (n == 0)
	{
		perror("L<line_number>: usage: push integer \n");
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		perror("Error: malloc failed \n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!stack)
	{
		*stack = new_node;
	}
	while (temp && temp->next)
	{
		temp = temp->next;
	}
	new_node->prev = temp;
	temp->next = new_node;
}

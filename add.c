#include "monte.h"
/**
 * add_ints - adds the top two elements
 * @line_number: unused variable
 * @stack: pointer to a linked list representation of a stack or queue
 */
void add_ints(stack_t **stack, __attribute__((unused)) unsigned int line_number
)
{
	stack_t *temp = *stack;
	int len = 0;

	while (temp)
	{
		len++;
		temp = temp->next;
	}
	if (!stack || len < 2)
	{
		perror("L<line_number>: can't add, stack too short \n");
		exit(EXIT_FAILURE);
	}
	temp->prev->n = temp->prev->n + temp->n;
	temp->prev->next = NULL;
	free(temp);
}

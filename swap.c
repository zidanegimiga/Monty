#include "monte.h"

/**
 * swap_int - swaps the top two elements of the stack
 * @line_number: unused varaible
 * @stack: pointer to a doubly linked list
 */
void swap_int(stack_t **stack, __attribute__((unused)) unsigned int line_number
)
{
	stack_t *temp = *stack;
	int tmp, len = 0;

	while (temp)
	{
		len++;
		temp = temp->next;
	}
	if (!stack || len < 2)
	{
		perror("L<line_number>: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}
	tmp = temp->prev->n;
	temp->prev->n = temp->n;
	temp->n = tmp;
}

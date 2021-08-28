#include "monte.h"

/**
 * pint - prints value at the top of the stack,followed by a new line
 * @line_number: unused variable
 * @stack: pointer to a doubly linked list
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!stack)
	{
		perror("L<line_number>: can't pint, stack empty \n");
		exit(EXIT_FAILURE);
	}
	while (temp && temp->next)
	{
		temp = temp->next;
	}
	printf("%d\n", temp->n);
}

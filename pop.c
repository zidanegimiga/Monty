#include "monte.h"
/**
 * pop_int - removes the top element of the stack
 * @line_number: unused variable
 * @stack: pointer to a doubly linked list
 */

void pop_int(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!stack)
	{
		perror("L<line_number>: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	while (stack && temp)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);
}

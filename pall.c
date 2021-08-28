#include "monte.h"
/**
 * pall - prints all values on the stack
 * @line_number: unused variable
 * @stack: pointer to a doubly linked list
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (stack)
	{
		while (stack)
		{
			printf("%d\n", (*stack)->n);
			*stack = (*stack)->next;
		}
	}
}

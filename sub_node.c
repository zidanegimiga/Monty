#include "monty.h"

/**
 * sub_node - subtracts the top element from the 2nd element in the stack
 * @head: double pointer to head node of stack
 * @line_number: line number of instruction in the file being read
 *
 * Return: no return value (void)
 */
void sub_node(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int sub = 0, count = 0;

	while (current != NULL)
	{
		current = (current)->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		int_arg = -1;
		return;
	}
	current = *head;
	sub = current->next->n - current->n;
	pop_stack(head, line_number);
	pop_stack(head, line_number);
	push_stack(head, sub);
}

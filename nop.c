#include "monte.h"
/**
 * nop_nop - does nothing
 * @line_number: unused variable
 * @stack: unused variable
 */
void nop_nop(__attribute__((unused)) stack_t **stack, __attribute__((unused))
unsigned int line_number)
{
	exit(EXIT_SUCCESS);
}

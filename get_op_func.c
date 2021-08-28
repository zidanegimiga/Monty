#include "monte.h"
/**
 * get_op_func - find the appropriate function given an instruction
 * from a byte code line
 * @line_opcode: opcode read from line
 * Return: pointer to the function that corresponds to the opcode
 */
void (*get_op_func(char *line_opcode))(stack_t **, unsigned int)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop_int},
		{"swap", swap_int},
		{"add", add_ints},
		{"nop", nop_nop},
		{NULL, NULL}
	};
	int i = 0;

	while (instruct[i].opcode)
	{
		if (strcmp(line_opcode, instruct[i].opcode) == 0)
			return (instruct[i].f);

		i++;
	}
	return (NULL);
}

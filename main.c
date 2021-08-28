#include "monte.h"
/**
 * main - interprets monty byte code
 * @argc: argument count passed by user from the terminal
 * @argv: array of commands passed by user
 * Return: tbd
 */
int main(int argc, char **argv)
{
	FILE *fileptr = fopen(argv[1], "r");
	char *line_opcode;
	stack_t *stacknode = malloc(sizeof(stack_t));
	stack_t **head = &stacknode;
	char **all_lines;
	char **line_chunks;
	unsigned int line_idx = 0;
	void (*function)(stack_t **, unsigned int);

	if (argc <= 1)
	{
		perror("USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}
	if (!fileptr)
	{
		perror("Error: Can\'t open file <>\n");
		exit(EXIT_FAILURE);
	}
	all_lines = readlines(fileptr);
	while (all_lines[line_idx])
	{
		line_chunks = tokenizer(all_lines[line_idx]);
		line_opcode = get_op(line_chunks);
		function = get_op_func(line_opcode);
		if (!function)
		{
			perror("L<line_number>: unknown instruction <opcode>");
			exit(EXIT_FAILURE);
		}
		function(head, (line_idx + 1));
		line_idx++;
	}
	fclose(fileptr);
	return (0);
}

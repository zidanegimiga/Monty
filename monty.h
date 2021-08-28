#ifndef MONTE_H
#define MONTE_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* fileptr points to file with byte code*/

extern FILE *fileptr;
FILE *fileptr;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* prototypes */
char **readlines(FILE *filepointer);
char **tokenizer(char *lines);
char *get_op(char **tokens);
int op_arg(char **tokens);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop_int(stack_t **stack, unsigned int line_number);
void swap_int(stack_t **stack, unsigned int line_number);
void add_ints(stack_t **stack, unsigned int line_number);
void nop_nop(stack_t **stack, unsigned int line_number);
void (*get_op_func(char *line_opcode))(stack_t **, unsigned int);
#endif

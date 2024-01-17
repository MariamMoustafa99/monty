#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void nodes_add(stack_t **, unsigned int);
void nodes_sub(stack_t **, unsigned int);
void nodes_div(stack_t **, unsigned int);
void nodes_mul(stack_t **, unsigned int);
void nodes_mod(stack_t **, unsigned int);


void char_pr(stack_t **, unsigned int);
void str_pr(stack_t **, unsigned int);
void rot_l(stack_t **, unsigned int);

void nodes_swap(stack_t **, unsigned int);
void top_pop(stack_t **, unsigned int);
void top_pr(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

void func_call(op_func, char *, char *, int, int);

void err_pr(int, ...);
void more_err_pr(int, ...);
void err_str(int, ...);
void rot_r(stack_t **, unsigned int);

stack_t *node_cr(int n);
void nodes_free(void);
void stack_pr(stack_t **, unsigned int);
void stack_add(stack_t **, unsigned int);
void queue_add(stack_t **, unsigned int);

void file_open(char *);
void file_read(FILE *);
int line_parse(char *, int, int);
int chars_length(FILE *);
void func_find(char *, char *, int, int);

#endif

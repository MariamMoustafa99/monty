#include "monty.h"

/**
 * nodes_mul - function that multiplies the top two elements of the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @ln:  the line number of the opcode.
 * Return: void
 */
void nodes_mul(stack_t **st, unsigned int ln)
{
	int mul;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		more_err_pr(8, ln, "mul");

	(*st) = (*st)->next;
	mul = (*st)->n * (*st)->prev->n;
	(*st)->n = mul;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * nodes_mod - function that gets the modulus of the
 * top two elements of the stack.
 * @st: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 * Return: void
 */
void nodes_mod(stack_t **st, unsigned int ln)
{
	int mod;

	if (st == NULL || *st == NULL || (*st)->next == NULL)

		more_err_pr(8, ln, "mod");


	if ((*st)->n == 0)
		more_err_pr(9, ln);
	(*st) = (*st)->next;
	mod = (*st)->n % (*st)->prev->n;
	(*st)->n = mod;
	free((*st)->prev);
	(*st)->prev = NULL;
}


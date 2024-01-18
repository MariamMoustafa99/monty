#include "monty.h"

/**
 * nop - function that does nothing
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void nop(stack_t **st, unsigned int ln)
{
	(void)st;
	(void)ln;
}


/**
 * nodes_swap - function that swaps the top two elements of the stack
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void nodes_swap(stack_t **st, unsigned int ln)
{
	stack_t *temp;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		more_err_pr(8, ln, "swap");
	temp = (*st)->next;
	(*st)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *st;
	temp->next = *st;
	(*st)->prev = temp;
	temp->prev = NULL;
	*st = temp;
}

/**
 * nodes_add - function that adds the top two elements of the stack
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void nodes_add(stack_t **st, unsigned int ln)
{
	int add;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		more_err_pr(8, ln, "add");

	(*st) = (*st)->next;
	add = (*st)->n + (*st)->prev->n;
	(*st)->n = add;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * nodes_sub - function that subtract the top two elements of the stack
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void nodes_sub(stack_t **st, unsigned int ln)
{
	int sub;

	if (st == NULL || *st == NULL || (*st)->next == NULL)

		more_err_pr(8, ln, "sub");


	(*st) = (*st)->next;
	sub = (*st)->n - (*st)->prev->n;
	(*st)->n = sub;
	free((*st)->prev);
	(*st)->prev = NULL;
}


/**
 * nodes_div - function that divides the top two elements of the stack
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void nodes_div(stack_t **st, unsigned int ln)
{
	int div;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		more_err_pr(8, ln, "div");

	if ((*st)->n == 0)
		more_err_pr(9, ln);
	(*st) = (*st)->next;
	div = (*st)->n / (*st)->prev->n;
	(*st)->n = div;
	free((*st)->prev);
	(*st)->prev = NULL;
}

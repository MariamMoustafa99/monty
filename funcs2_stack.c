#include "monty.h"


/**
 * stack_add - function that adds a node to the stack
 * @nnode: Pointer to the new node.
 * @line_num: the line number of the opcode
 */
void stack_add(stack_t **nnode, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (nnode == NULL || *nnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nnode;
		return;
	}
	temp = head;
	head = *nnode;
	head->next = temp;
	temp->prev = head;
}


/**
 * stack_pr - function that print nodes of the stack
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void stack_pr(stack_t **st, unsigned int ln)
{
	stack_t *temp;

	(void) ln;
	if (st == NULL)
		exit(EXIT_FAILURE);
	temp = *st;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * top_pop - function that pops the top node from the stack
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void top_pop(stack_t **st, unsigned int ln)
{
	stack_t *temp;

	if (st == NULL || *st == NULL)
		more_err_pr(7, ln);

	temp = *st;
	*st = temp->next;
	if (*st != NULL)
		(*st)->prev = NULL;
	free(temp);
}

/**
 * top_pr - function that prints the top node of the stack
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void top_pr(stack_t **st, unsigned int ln)
{
	if (st == NULL || *st == NULL)
		more_err_pr(6, ln);
	printf("%d\n", (*st)->n);
}


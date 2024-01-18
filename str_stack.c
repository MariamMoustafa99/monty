#include "monty.h"

/**
 * char_pr - function that prints the Ascii values
 * @st: Pointer to a pointer to top node of the stack
 * @ln: the line number of the opcode
 */
void char_pr(stack_t **st, unsigned int ln)
{
	int val;

	if (st == NULL || *st == NULL)
		err_str(11, ln);

	val = (*st)->n;
	if (val < 0 || val > 127)
		err_str(10, ln);
	printf("%c\n", val);
}

/**
 * str_pr - function that prints a string
 * @st: Pointer to a pointer to top node of the stack
 * @line_num: the line number of the opcode
 */
void str_pr(stack_t **st, __attribute__((unused))unsigned int line_num)
{
	int val;
	stack_t *temp;

	if (st == NULL || *st == NULL)
	{
		printf("\n");
		return;
	}

	temp = *st;
	while (temp != NULL)
	{
		val = temp->n;
		if (val <= 0 || val > 127)
			break;
		printf("%c", val);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rot_l - function that rotates the first node of the stack to the bottom
 * @st: Pointer to a pointer to top node of the stack
 * @line_num: the line number of the opcode
 */
void rot_l(stack_t **st, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	temp = *st;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *st;
	(*st)->prev = temp;
	*st = (*st)->next;
	(*st)->prev->next = NULL;
	(*st)->prev = NULL;
}


/**
 * rot_r - function that rotates the last node of the stack to the top
 * @st: Pointer to a pointer to top node of the stack
 * @line_num: the line number of the opcode
 */
void rot_r(stack_t **st, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (st == NULL || *st == NULL || (*st)->next == NULL)
		return;

	temp = *st;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *st;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*st)->prev = temp;
	(*st) = temp;
}


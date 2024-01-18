#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point
 * @arg_c: arguments count
 * @arg_v: list of arguments
 * Return: always 0
 */

int main(int arg_c, char *arg_v[])
{
	if (arg_c != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_open(arg_v[1]);
	nodes_free();
	return (0);
}

/**
 * node_cr - function that creates a node.
 * @num: Number to go inside the node.
 * Return: on success a pointer to the node. Otherwise NULL.
 */
stack_t *node_cr(int num)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_pr(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = num;
	return (node);
}

/**
 * nodes_free - function that frees nodes in the stack.
 */
void nodes_free(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * queue_add - function that adds a node to the queue.
 * @nnode: Pointer to the new node.
 * @line_num: line number of the opcode.
 */
void queue_add(stack_t **nnode, __attribute__((unused))unsigned int line_num)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *nnode;
	(*nnode)->prev = temp;

}


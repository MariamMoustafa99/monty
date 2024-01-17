#include "monty.h"

/**
 * file_open - function that opens a file
 * @fname: the file name path
 * Return: void
 */

void file_open(char *fname)
{
	FILE *f_des = fopen(fname, "r");

	if (fname == NULL || f_des == NULL)
		err(2, fname);

	file_read(f_des);
	fclose(f_des);
}


/**
 * file_read - function that reads a file
 * @f_des: pointer to file descriptor
 * Return: void
 */

void file_read(FILE *f_des)
{
	int ln, form = 0;
	char *buf = NULL;
	size_t length = 0;

	for (ln = 1; getline(&buf, &length, f_des) != -1; ln++)
	{
		form = line_parse(buf, ln, form);
	}
	free(buf);
}


/**
 * line_parse - function that separates each line into tokens
 * @buf: line from the file
 * @ln: line number
 * @form: storage format if 0 nodes will be entered as a stack &
 * if 1 node will be entered as a queue.
 * Return: 0 if the opcode is stack & 1 if queue
 */

int line_parse(char *buf, int ln, int form)
{
	char *op_code, *val;
	const char *del = "\n ";

	if (buf == NULL)
		err(4);

	op_code = strtok(buf, del);
	if (op_code == NULL)
		return (form);
	val = strtok(NULL, del);

	if (strcmp(op_code, "stack") == 0)
		return (0);
	if (strcmp(op_code, "queue") == 0)
		return (1);

	func_find(op_code, val, ln, form);
	return (form);
}

/**
 * func_find - function that finds the appropriate function for the opcode
 * @op_code: opcode
 * @val: value of opcode
 * @form: storage format if 0 nodes will be entered as a stack &
 * if 1 node will be entered as a queue.
 * @ln: line number
 * Return: void
 */
void func_find(char *op_code, char *val, int ln, int form)
{
	int k;
	int f_lag;

	instruction_t func_list[] = {
		{"push", stack_add},
		{"pall", stack_pr},
		{"pint", top_pr},
		{"pop", top_pop},
		{"nop", nop},
		{"swap", nodes_swap},
		{"add", nodes_add},
		{"sub", nodes_sub},
		{"div", nodes_div},
		{"mul", nodes_mul},
		{"mod", nodes_mod},
		{"pchar", char_pr},
		{"pstr", str_pr},
		{"rotl", rot_l},
		{"rotr", rot_r},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return;

	for (f_lag = 1, k = 0; func_list[k].op_code != NULL; k++)
	{
		if (strcmp(op_code, func_list[k].op_code) == 0)
		{
			func_call(func_list[k].f, op_code, val, ln, form);
			f_lag = 0;
		}
	}
	if (f_lag == 1)
		err_pr(3, ln, op_code);
}


/**
 * func_call - function that calls the required function
 * @func: Pointer to the function that is about to be called
 * @op_code: string representing the opcode.
 * @value: string representing a numeric value.
 * @ln: line numeber
 * @form: storage format if 0 nodes will be entered as a stack &
 * if 1 node will be entered as a queue.
 */
void func_call(op_func func, char *op_code, char *value, int ln, int form)
{
	stack_t *n;
	int f_lag;
	int k;

	f_lag = 1;
	if (strcmp(op_code, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			f_lag = -1;
		}
		if (value == NULL)
			err_pr(5, ln);
		for (k = 0; value[k] != '\0'; k++)
		{
			if (isdigit(value[k]) == 0)
				err_pr(5, ln);
		}
		n = node_cr(atoi(value) * f_lag);
		if (form == 0)
			func(&n, ln);
		if (form == 1)
			queue_add(&n, ln);
	}
	else
		func(&head, ln);
}


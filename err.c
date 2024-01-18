#include "monty.h"

/**
 * err_pr - function that prints appropiate error messages according to the error code
 * @err_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 */
void err_pr(int err_code, ...)
{
	va_list arg;
	char *op_code;
	int line_num;

	va_start(arg, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			line_num = va_arg(arg, int);
			op_code = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * more_err_pr - function that handles errors.
 * @err_code: The error codes are the following:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_err_pr(int err_code, ...)
{
	va_list arg;
	char *op_code;
	int line_num;

	va_start(arg, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			line_num = va_arg(arg, unsigned int);
			op_code = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op_code);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * err_str - function that handles errors.
 * @err_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void err_str(int err_code, ...)
{
	va_list arg;
	int line_num;

	va_start(arg, err_code);
	line_num = va_arg(arg, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

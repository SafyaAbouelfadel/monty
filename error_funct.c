#include "monty.h"

/**
 * free_node - Frees nodes in the stack.
 */
void free_node(void)
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
 * errors - Displays error messages based on the error code.
 * @error_msg: The error codes are:
 * (1) => No file or multiple files provided to the program.
 * (2) => File cannot be opened or read.
 * (3) => Invalid instruction in the file.
 * (4) => Memory allocation failure.
 * (5) => Non-integer parameter passed to "push" instruction.
 * (6) => Empty stack for "pint" operation.
 * (7) => Empty stack for "pop" operation.
 * (8) => Stack too short for the operation.
 */
void errors(int error_msg, ...)
{
	va_list argum;
	char *opcd;
	int line_num;

	va_start(argum, error_msg);
	switch (error_msg)
	{
		case 1:
			fprintf(stderr, "usage: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argum, char *));
			break;
		case 3:
			line_num = va_arg(argum, int);
			opcd = va_arg(argum, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcd);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argum, int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - Handles additional error cases.
 * @error_msg: The error codes are:
 * (6) => Empty stack for "pint" operation.
 * (7) => Empty stack for "pop" operation.
 * (8) => Stack too short for the operation.
 * (9) => Division by zero.
 */

void more_errors(int error_msg, ...)
{
	va_list argum;
	char *opcd;
	int line_num;

	va_start(argum, error_msg);
	switch (error_msg)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(argum, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(argum, int));
			break;
		case 8:
			line_num = va_arg(argum, unsigned int);
			opcd = va_arg(argum, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, opcd);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(argum, unsigned int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * string_errors - Handles errors for the "pchar" operation.
 * @error_msg: The error codes are:
 * (10) => The value in a node is outside the ASCII range.
 * (11) => The stack is empty.
 */

void string_errors(int error_msg, ...)
{
	va_list argum;
	int line_num;

	va_start(argum, error_msg);
	line_num = va_arg(argum, int);
	switch (error_msg)
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
	free_node();
	exit(EXIT_FAILURE);
}

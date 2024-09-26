#include "monty.h"

/**
 * file_open - opens a file
 * @file_n: the file name path
 * Return: void
 */

void file_open(char *file_n)
{
	FILE *file_d = fopen(file_n, "r");

	if (file_n == NULL || file_d == NULL)
		errors(2, file_n);

	file_read(file_d);
	fclose(file_d);
}
/**
 * tokenize_line - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @l_num: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int tokenize_line(char *buff, int l_num, int format)
{
	char *opcode, *num;
	const char *deli = "\n ";

	if (buff == NULL)
		errors(4);

	opcode = strtok(buff, deli);
	if (opcode == NULL)
		return (format);
	num = strtok(NULL, deli);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, num, l_num, format);
	return (format);
}

/**
 * file_read - reads a file
 * @file_d: pointer to the file descriptor
 * Return: void
 */

void file_read(FILE *file_d)
{
	int line_num, format = 0;
	char *buff = NULL;
	size_t l = 0;

	for (line_num = 1; getline(&buff, &l, file_d) != -1; line_num++)
	{
		format = tokenize_line(buff, line_num, format);
	}
	free(buff);
}

/**
 * find_function - find the appropriate opcode function
 * @opcode: the opcode
 * @val: argument of opcode
 * @line: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_function(char *opcode, char *val, int line, int format)
{
	int k;
	int flag;

	operation_t fun_list[] = {
		{"push", add_node_stack},
		{"pall", print_all_stack},
		{"pint", print_top_node},
		{"pop", pop_top_node},
		{"nop", op_nop},
		{"swap", swap_stack_nodes},
		{"add", add_stack_nodes},
		{"sub", sub_stack_nodes},
		{"div", div_stack_nodes},
		{"mul", mul_stack_nodes},
		{"mod", mod_stack_nodes},
		{"pchar", show_char},
		{"pstr", show_str},
		{"rotl", rot_last},
		{"rotr", rot_top},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, k = 0; fun_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, fun_list[k].opcode) == 0)
		{
			call_func(fun_list[k].f, opcode, val, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, line, opcode);
}

/**
 * call_func - Calls the required function.
 * @fun: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @value: string representing a numeric value.
 * @line: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func(ops_func fun, char *opcode, char *value, int line, int format)
{
	stack_t *node;
	int flag;
	int k;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			errors(5, line);
		for (k = 0; value[k] != '\0'; k++)
		{
			if (isdigit(value[k]) == 0)
				errors(5, line);
		}
		node = init_node(atoi(value) * flag);
		if (format == 0)
			fun(&node, line);
		if (format == 1)
			add_node_queue(&node, line);
	}
	else
		fun(&head, line);
}

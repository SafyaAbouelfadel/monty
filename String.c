#include "monty.h"

/**
 * show_char - Prints the Ascii value.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void show_char(stack_t **stk, unsigned int line_num)
{
	int ascii_char;

	if (stk == NULL || *stk == NULL)
		string_errors(11, line_num);

	ascii_char = (*stk)->n;
	if (ascii_char < 0 || ascii_char > 127)
		string_errors(10, line_num);
	printf("%c\n", ascii_char);
}

/**
 * show_str - Prints a string.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void show_str(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	int ascii_char;
	stack_t *temp;

	if (stk == NULL || *stk == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stk;
	while (temp != NULL)
	{
		ascii_char = temp->n;
		if (ascii_char <= 0 || ascii_char > 127)
			break;
		printf("%c", ascii_char);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rot_last - Rotates the first node of the stack to the bottom.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rot_last(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	temp = *stk;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stk;
	(*stk)->prev = temp;
	*stk = (*stk)->next;
	(*stk)->prev->next = NULL;
	(*stk)->prev = NULL;
}


/**
 * rot_top - Rotates the last node of the stack to the top.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rot_top(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	temp = *stk;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stk;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stk)->prev = temp;
	(*stk) = temp;
}

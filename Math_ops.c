#include "monty.h"

/**
 * add_stack_nodes - Adds top two elements of a stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void add_stack_nodes(stack_t **stk, unsigned int line_num)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		more_errors(8, line_num, "add");

	(*stk) = (*stk)->next;
	sum = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * sub_stack_nodes - sub top two elements of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void sub_stack_nodes(stack_t **stk, unsigned int line_num)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

		more_errors(8, line_num, "sub");


	(*stk) = (*stk)->next;
	sum = (*stk)->n - (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

/**
 * div_stack_nodes - divide top two elements of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void div_stack_nodes(stack_t **stk, unsigned int line_num)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		more_errors(8, line_num, "div");

	if ((*stk)->n == 0)
		more_errors(9, line_num);
	(*stk) = (*stk)->next;
	sum = (*stk)->n / (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

/**
 * mul_stack_nodes - multiply top two elements of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void mul_stack_nodes(stack_t **stk, unsigned int line_num)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		more_errors(8, line_num, "mul");

	(*stk) = (*stk)->next;
	sum = (*stk)->n * (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * mod_stack_nodes - calculate the mode of top two elements of the stack.
 * @stk: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void mod_stack_nodes(stack_t **stk, unsigned int line_num)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

		more_errors(8, line_num, "mod");


	if ((*stk)->n == 0)
		more_errors(9, line_num);
	(*stk) = (*stk)->next;
	sum = (*stk)->n % (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

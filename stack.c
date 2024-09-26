#include "monty.h"

/**
 * pop_top_node - delete the top node of the stack.
 * @stk: Pointer to a pointer to the top node of the stack.
 * @line_num: the line number of the opcode.
 */
void pop_top_node(stack_t **stk, unsigned int line_num)
{
	stack_t *temp;

	if (stk == NULL || *stk == NULL)
		more_errors(7, line_num);

	temp = *stk;
	*stk = temp->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	free(temp);
}

/**
 * print_top_node - Prints the top node of the stack.
 * @stk: Pointer to a pointer to the top node of the stack.
 * @line_num: the line number of the opcode.
 */
void print_top_node(stack_t **stk, unsigned int line_num)
{
	if (stk == NULL || *stk == NULL)
		more_errors(6, line_num);
	printf("%d\n", (*stk)->num);
}

/**
 * op_nop - Does nothing.
 * @stk: Pointer to a pointer to the top node of the stack.
 * @line_num: the line number of the opcode.
 */
void op_nop(stack_t **stk, unsigned int line_num)
{
	(void)stk;
	(void)line_num;
}


/**
 * swap_stack_nodes - Swaps the top two elements of the stack.
 * @stk: Pointer to a pointer to the top node of the stack.
 * @line_num: the line number of the opcode.
 */
void swap_stack_nodes(stack_t **stk, unsigned int line_num)
{
	stack_t *tmp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		more_errors(8, line_num, "swap");
	tmp = (*stk)->next;
	(*stk)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stk;
	tmp->next = *stk;
	(*stk)->prev = tmp;
	tmp->prev = NULL;
	*stk = tmp;
}

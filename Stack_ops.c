#include "monty.h"

/**
 * init_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *init_node(int n)
{
	stack_t *c_node;

	c_node = malloc(sizeof(stack_t));
	if (c_node == NULL)
		errors(4);
	c_node->next = NULL;
	c_node->prev = NULL;
	c_node->num = n;
	return (c_node);
}



/**
 * add_node_queue - Adds a node to the queue.
 * @n_node: Pointer to the new node.
 * @l: line number of the opcode.
 */
void add_node_queue(stack_t **n_node, __attribute__((unused))unsigned int l)
{
	stack_t *temp;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *n_node;
	(*n_node)->prev = temp;

}

/**
 * add_node_stack - Adds a node to the stack.
 * @n_node: Pointer to the new node.
 * @l: Interger representing the line number of of the opcode.
 */
void add_node_stack(stack_t **n_node, __attribute__((unused))unsigned int l)
{
	stack_t *temp;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	temp = head;
	head = *n_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_all_stack - print all nodes of the stack.
 * @stk: Pointer to a pointer to top node of the stack.
 * @l_number: line number of the opcode.
 */
void print_all_stack(stack_t **stk, unsigned int l_number)
{
	stack_t *temp;

	(void) l_number;
	if (list == NULL)
		exit(EXIT_FAILURE);
	temp = *stk;
	while (temp != NULL)
	{
		printf("%d\n", temp->num);
		temp = temp->next;
	}
}

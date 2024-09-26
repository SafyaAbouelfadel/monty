#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*ops_func)(stack_t **, unsigned int);

/*file_ops.c*/
void file_open(char *file_n);
int tokenize_line(char *buff, int l_num, int format);
void file_read(FILE *);
void find_function(char *opcode, char *val, int line, int format);
void call_func(ops_func fun, char *opcode, char *value, int line, int format);

/*Stack_ops.c*/
stack_t *init_node(int n);
void print_all_stack(stack_t **, unsigned int);
void add_node_stack(stack_t **n_node, __attribute__((unused))unsigned int l);
void add_node_queue(stack_t **n_node, __attribute__((unused))unsigned int l);

/*stack.c*/
void print_top_node(stack_t **, unsigned int);
void pop_top_node(stack_t **, unsigned int);
void op_nop(stack_t **, unsigned int);
void swap_stack_nodes(stack_t **, unsigned int);

/*Math_ops.c*/
void add_stack_nodes(stack_t **stk, unsigned int line_num);
void sub_stack_nodes(stack_t **stk, unsigned int line_num);
void div_stack_nodes(stack_t **stk, unsigned int line_num);
void mul_stack_nodes(stack_t **stk, unsigned int line_num);
void mod_stack_nodes(stack_t **stk, unsigned int line_num);

/*String.c*/
void show_char(stack_t **stk, unsigned int line_num);
void show_str(stack_t **stk, __attribute__((unused))unsigned int ln);
void rot_last(stack_t **stk, __attribute__((unused))unsigned int ln);
void rot_top(stack_t **stk, __attribute__((unused))unsigned int ln);

/*error_funct.c comlite*/
void free_node(void);
void errors(int error_msg, ...);
void more_errors(int error_msg, ...);
void string_errors(int error_msg, ...);

#endif

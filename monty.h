#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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
 * struct data_s - data structure for Monty interpreter
 * @argument: argument value
 * @monty_file: pointer to the Monty file
 * @line_content: content of the current line
 * @stack_mode: flag indicating stack or queue mode
 *
 * Description: Structure to carry data through the Monty interpreter.
 */
typedef struct data_s
{
    char *argument;
    FILE *monty_file;
    char *line_content;
    int stack_mode;
}  data_t;

extern data_t program_data;

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




void pint_handler(stack_t **stack, unsigned int line_counter);
void free_stack_memory(stack_t *stack);
void pop_handler(stack_t **stack, unsigned int line_counter);
void swap_handler(stack_t **stack, unsigned int line_counter);
void add_handler(stack_t **stack, unsigned int line_counter);
void nop_handler(stack_t **stack, unsigned int line_counter);
void sub_handler(stack_t **stack, unsigned int line_counter);
int execute(char *line_content, stack_t **stack, unsigned int line_counter, FILE *monty_file);
void push_handler(stack_t **stack, unsigned int line_counter)
void pall_handler(stack_t **stack, unsigned int line_counter)
void add_node_to_queue(stack_t **stack, int value);
void queue_handler(stack_t **stack, unsigned int line_counter);
void add_node_to_stack(stack_t **stack, int n);
#endif

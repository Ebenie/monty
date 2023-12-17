#include "monty.h"

/**
 * queue_handler - sets the queue mode
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty file
 * Return: no return
 */
void queue_handler(stack_t **stack, unsigned int line_counter)
{
    (void)stack;
    (void)line_counter;
    program_data.stack_mode = 1;
}

/**
 * add_node_to_queue - adds a node to the tail of the stack
 * @stack: pointer to the head of the stack
 * @value: new value
 * Return: no return
 */
void add_node_to_queue(stack_t **stack, int value)
{
    stack_t *new_node, *current_node;

    current_node = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->next = NULL;

    if (current_node)
    {
        while (current_node->next)
            current_node = current_node->next;
    }

    if (!current_node)
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    else
    {
        current_node->next = new_node;
        new_node->prev = current_node;
    }
}


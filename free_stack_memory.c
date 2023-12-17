#include "monty.h"

/**
 * free_stack_memory - frees a doubly linked list
 * @stack: head of the stack
 */
void free_stack_memory(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

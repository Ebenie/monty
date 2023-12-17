#include "monty.h"
/**
 * nop_handler - does nothing
 * @stack: pointer to the stack head
 * @line_counter: line number
 * Return: No return value
 */
void nop_handler(stack_t **stack, unsigned int line_counter)
{
    (void)line_counter;
    (void)stack;
}

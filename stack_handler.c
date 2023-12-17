#include "monty.h"

/**
 * stack_handler - sets the stack mode
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty file
 * Return: no return
 */
void stack_handler(stack_t **stack, unsigned int line_counter)
{
    (void)stack;
    (void)line_counter;
    program_data.stack_mode = 0;
}

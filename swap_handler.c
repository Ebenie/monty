#include "monty.h"
/**
 * swap_handler - swaps the top two elements of the stack
 * @stack: pointer to the stack head
 * @line_counter: line number
 * Return: No return value
 */
void swap_handler(stack_t **stack, unsigned int line_counter)
{
    stack_t *current = *stack;
    int len = 0, temp;

    while (current)
    {
        current = current->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_counter);
        fclose(program_data.monty_file);
        free(program_data.line_content);
        free_stack_memory(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    temp = current->n;
    current->n = current->next->n;
    current->next->n = temp;
}

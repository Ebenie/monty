#include "monty.h"
/**
 * add_handler - adds the top two elements of the stack
 * @stack: pointer to the stack head
 * @line_counter: line number
 * Return: No return value
 */
void add_handler(stack_t **stack, unsigned int line_counter)
{
    stack_t *current = *stack;
    int len = 0, result;

    while (current)
    {
        current = current->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_counter);
        fclose(program_data.monty_file);
        free(program_data.line_content);
        free_stack_memory(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    result = current->n + current->next->n;
    current->next->n = result;
    *stack = current->next;
    free(current);
}

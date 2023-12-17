#include "monty.h"
/**
 * pop_handler - removes the top element of the stack
 * @stack: pointer to the stack head
 * @line_counter: line number
 * Return: No return value
 */
void pop_handler(stack_t **stack, unsigned int line_counter)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_counter);
        fclose(program_data.monty_file);
        free(program_data.line_content);
        free_stack_memory(*stack);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;
    free(temp);
}

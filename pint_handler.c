#include "monty.h"
/**
 * pint_handler - prints the top element of the stack
 * @stack: pointer to the stack head
 * @line_counter: line number
 * Return: No return value
 */
void pint_handler(stack_t **stack, unsigned int line_counter)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
        fclose(program_data.monty_file);
        free(program_data.line_content);
        free_stack_memory(*stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

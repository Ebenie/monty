#include "monty.h"
/**
 * sub_handler - subtracts the top element of the stack from the second top element
 * @stack: pointer to the stack head
 * @line_counter: line number
 * Return: No return value
 */
void sub_handler(stack_t **stack, unsigned int line_counter)
{
    stack_t *temp;
    int difference, node_count;

    temp = *stack;
    for (node_count = 0; temp != NULL; node_count++)
        temp = temp->next;

    if (node_count < 2)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_counter);
        fclose(program_data.monty_file);
        free(program_data.line_content);
        free_stack_memory(*stack);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    difference = temp->next->n - temp->n;
    temp->next->n = difference;
    *stack = temp->next;
    free(temp);
}

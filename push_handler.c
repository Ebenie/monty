#include "monty.h"

/**
 * push_handler - adds a node to the stack
 * @stack: pointer to the head of the stack
 * @line_counter: line number in the Monty file
 * Return: no return
 */
void push_handler(stack_t **stack, unsigned int line_counter)
{
    int value, index = 0, flag = 0;

    if (program_data.argument)
    {
        if (program_data.argument[0] == '-')
            index++;
        for (; program_data.argument[index] != '\0'; index++)
        {
            if (program_data.argument[index] > '9' || program_data.argument[index] < '0')
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_counter);
            fclose(program_data.monty_file);
            free(program_data.line_content);
            free_stack_memory(*stack);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_counter);
        fclose(program_data.monty_file);
        free(program_data.line_content);
        free_stack_memory(*stack);
        exit(EXIT_FAILURE);
    }

    value = atoi(program_data.argument);

    if (program_data.stack_mode == 0)
        add_node_to_stack(stack, value);
    else
        add_node_to_queue(stack, value);
}

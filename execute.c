#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to Monty file
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opst[] = {
        {"push", push_handler}, {"pall", pall_handler}, {"pint", pint_handler},
        {"pop", pop_handler},
        {"swap", swap_handler},
        {"add", add_handler},
        {"nop", nop_handler},
        {"sub", sub_handler},
        {"rotr", rotr_handler},
        {"queue", queue_handler},
        {"stack", stack_handler},
        {NULL, NULL}
    };

    unsigned int i = 0;
    char *op;

    op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return 0;

    program_data.argument = strtok(NULL, " \n\t");

    while (opst[i].opcode && op)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            opst[i].f(stack, counter);
            return 0;
        }
        i++;
    }

    if (op && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack_memory(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;
}

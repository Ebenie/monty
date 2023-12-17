#include "monty.h"
/**
 * f_pall - prints the stack
 * @stack: stack head
 * @line_counter: no used
 * Return: no return
*/
void pall_handler(stack_t **stack, unsigned int line_counter)
{
	stack_t *h;
	(void)line_counter;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

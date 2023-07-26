#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void)line_number;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

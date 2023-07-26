#include "monty.h"

/**
 * free_stack - Frees all the nodes in the stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *curr;

	while (stack)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
	}
}

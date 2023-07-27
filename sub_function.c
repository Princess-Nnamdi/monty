#include "monty.h"

/**
 * sub - subtracts the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 **/

void sub(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

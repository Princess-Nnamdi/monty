#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int j;
	char *endptr;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	j = strtol(vglo.arg, &endptr, 10);
	if (*endptr != '\0')
	{
		dprintf(2, "L%u: usage: push integer\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if (vglo.lifo == 1)
		add_dnodeint(stack, j);
	else
		add_dnodeint_end(stack, j);
}

#include "monty.h"

#include <stdio.h>
#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}

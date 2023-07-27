#include "monty.h"

/*
 * queue_function - converts a stack to a queue
 * stack - pointer to head of linked list
 * line_number - line number
 **/

void stack_function(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void)line_number;
	while (curr)
	{
		curr->is_queue = 0;
		curr = curr->next;
	}
}

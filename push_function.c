#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");

	stack_t *new_node = malloc(sizeof(stack_t));

	if (arg == NULL || new_node == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

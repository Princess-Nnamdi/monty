#include "monty.h"

/**
 * parse_line - Parses a line of input and executes the corresponding opcode.
 * @line: The line of input to parse.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 *
 * Return: 0 on success, -1 on failure.
 */
int parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode = strtok(line, " \t\n"), *arg = strtok(NULL, " \t\n");
	int argument;

	while (*line == ' ' || *line == '\t')
		line++;
	if (opcode == NULL || opcode[0] == '#')
		return (0);
	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (-1);
		}
		argument = atoi(arg);
		push(stack, argument);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
	{

	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}
	return (0);
}

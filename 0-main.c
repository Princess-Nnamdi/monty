#include "monty.h"

/**
 * main - Entry point
 * argc: number of arguements
 * argv: array of arguements
 **/

global_t vglo;

/**
 * free_vglo - frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

#define MAX_LINE_LENGTH 1024
int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	size_t line_length;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		line_length = strlen(line);

		if (line_length > 0 && line[line_length - 1] == '\n')
			line[line_length - 1] = '\0';
		if (parse_line(line, &stack, line_number) == -1)
		{
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
	fclose(file);

	return (0);
}

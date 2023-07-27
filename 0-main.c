#include "monty.h"

global_t vglo;

/**
 * free_vglo - frees the global variables
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo - initializes the global variables
 * @fd: file descriptor
 */
void start_vglo(FILE *fd)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 * @argc: number of arguements
 * @argv: array of arguments
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
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

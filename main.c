#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	FILE *file;
	size_t bufsize = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	do {
		line = NULL;
		read_line = getline(&line, &bufsize, file);
		bus.content = line;
		line_number++;

		if (read_line > 0)
		{
			execute(line, &stack, line_number, file);
		}

		free(line);
	} while (read_line > 0);

	free_stack(stack);
	fclose(file);

	return (0);
}

#include "monty.h"

/**
 * parse_file - Read and process instructions from a file.
 * @filepath: Path to the file containing instructions.
 *
 * Return: void
 */
void parse_file(char *filepath, instruction_t *instructions)
{
	FILE *file;
	char *line, *token;
	size_t len;
	ssize_t read;
	unsigned int line_number;
	int i;

	len = 0, line = NULL, line_number = 0;
	file = fopen(filepath, "r");
	if (file == NULL)
	{ fprintf(stderr, "Error: Can't open file %s\n", filepath);
		exit(EXIT_FAILURE);
	}

	/* read each line */
	while ((read = getline(&line, &len, file)) != -1)
	{ char *opcode;
		unsigned int argument;

		line_number++;
		/* split line into opcode and argument */
		opcode = strtok(line, " \t\r\n");
		if (opcode == NULL || *opcode == '\0')
			continue;
		token = strtok(NULL, " \t\r\n");
		argument = token != NULL ? atoi(token) : 0;

		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{ instructions[i].f(&global_stack, argument);
				break;
			}
		}
		if (instructions[i].opcode == NULL)
		{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	} free(line);
	fclose(file);
}

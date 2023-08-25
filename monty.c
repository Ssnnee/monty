#include "monty.h"

stack_t *global_stack = NULL;

/**
 * main - The main function of the monty program.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments passed to the program.
 *
 * Return: The exit status of the monty program.
 */
int main(int argc, char **argv)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"divs", divs},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	parse_file(argv[1], instructions);
	return (0);
}

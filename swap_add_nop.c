#include "monty.h"

/**
 * swap -  Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int last_value;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	last_value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = last_value;
}

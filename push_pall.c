#include "monty.h"

/**
 * push - Push a value onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the instruction.
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* initialize the new node */
	/* replace line_number with the value to push */
	node->n = line_number;
	node->prev = NULL;
	node->next = *stack;

	/* update the previous pointer of the first node if stack is not empty */
	if (*stack != NULL)
		(*stack)->prev = node;

	/* update the head of the stack */
	*stack = node;
}

/**
 * pall - Print all elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the instruction
 * (unused, for compatibility).
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Print he value at the top of the stack,
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the instruction
 * (unused, for compatibility).
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if (temp != NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}

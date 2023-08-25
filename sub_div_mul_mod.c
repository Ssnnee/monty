#include "monty.h"

/**
 * sub -  Subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n -= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * divs -  Divides the second top element of
 * the stack by the top element of the stack.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void divs(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n /= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * mul - Multiplies the second top element of the
 * stack with the top element of the stack.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n *= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the instruction
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n %= temp->n;
	*stack = temp->next;
	free(temp);
}

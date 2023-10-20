#include "monty.h"
/**
 *add - function for add
 *@stack: struct of args
 *@line_number: line's numbers
 *Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int n1;
	int n2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n1 = (*stack)->n;
	n2 = (*stack)->next->n;
	(*stack)->next->n = n1 + n2;
	stack_pop(stack);
}
/**
 * nop - does nothing
 * @stack: struct of args
 * @line_number: number
 * Return: void
 */
void nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
}

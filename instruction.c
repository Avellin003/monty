#include "monty.h"
/**
 * push - function for push
 * @stack: struct of args
 * @line_number: line's number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (scanf("%d", &n) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_push(stack, n);
}
/**
 * pall - function for pall
 * @stack: struct of args
 * @line_number: line's numbers
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (*stack == NULL)
		return;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
/**
 * pint - function for pint
 *@stack: struct of args
 *@line_number: line's numbers
 *Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 *pop - function for pop
 *@stack: struct of args
 *@line_number: line's numbers
 *Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_pop(stack);
}
/**
 *swap - function for swap
 *@stack: struct of args
 *@line_number: line's numbers
 *Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int n1;
	int n2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n1 = (*stack)->n;
	n2 = (*stack)->next->n;
	(*stack)->n = n2;
	(*stack)->next->n = n1;
}

#include "monty.h"
/**
 * stack_new - makes new node
 * @n: int
 * Return: new_node
 */
stack_t *stack_new(int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
/**
 * stack_push - function
 * @n: int
 * @stack: pointer
 * Return: void
 */
void stack_push(stack_t **stack, int n)
{
	stack_t *new_node = stack_new(n);

	new_node->next = *stack;
	*stack = new_node; }
/**
 * stack_pop - pops stack
 * @stack: pointer
 * Return: int
 */
int stack_pop(stack_t **stack)
{
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "Error: can't pop an empty stack\n");
		exit(EXIT_FAILURE); }

	n = (*stack)->n;
	*stack = (*stack)->next;

	return (n);
}
/**
 * stack_free - frees stack
 * @stack: double pointer
 * Return: void
 */
void stack_free(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *next = stack->next;

		free(stack);
		stack = next;
	}
}

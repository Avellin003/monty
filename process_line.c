#include "monty.h"
/**
 * process_line - tokenizer
 * @line: pointer to the line
 * @line_number: line's number
 * Return: void
 */
void process_line(char *line, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {NULL, NULL}};
	int i = 0;
	char *token = strtok(line, " \t\n");

	if (token == NULL || token[0] == '#')
	{
		nop(&global.stack, line_number);
		return;
	}
	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, token) == 0)
		{
			instructions[i].f(&global.stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}

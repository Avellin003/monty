#include "monty.h"
#include <stdio.h>
global_t global = {NULL, NULL, NULL};
/**
 * main - program runner
 * @argc: argument count
 * @argv: argument vector
 * Return: integer
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	global.file = fopen(argv[1], "r");
	if (!global.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); }
	while (fgets(line, MAX, global.file) != NULL)
	{
		line_number++;
		line[strlen(line) - 1] = '\0';
		process_line(line, line_number); }
	fclose(global.file);
	stack_free(global.stack);
	return (0); }

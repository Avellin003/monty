#ifndef MONTY_H
#define MONTY_H
#define MAX 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct
{
    FILE *file;
    char *cont;
    stack_t *stack;
} global_t;

extern global_t global;
stack_t *stack_new(int n);
void stack_push(stack_t **stack, int n);
int stack_pop(stack_t **stack);
void stack_free(stack_t *stack);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void process_line(char *line, unsigned int line_number);
#endif


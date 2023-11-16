#include "monty.h"
/**
 * modus- computes the rest of the division same as div
 * @stack: the pizza stack
 * @line_number: the number to call for the pizza
*/
void modus(stack_t **stack, unsigned int line_number)
{
    int divoja = 0;
   if (!stack || !*stack ||(*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack) = (*stack)->next;
    divoja =(*stack)->n % (*stack)->prev->n;
    (*stack)->n = divoja;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
/**
 * pchar - prints char i guess
 * @stack: the pizza stack
 * @line_number: the number to call for the pizza
*/
void pchar(stack_t **stack, unsigned int line_number)
{
int asc;
if (!stack || !*stack)
{
    fprintf(stderr,"L%d: can't pchar, value out of range", line_number);
    exit(EXIT_FAILURE);
}
asc = (*stack)->n;
if (asc < 0 || asc > 127)
{
    fprintf(stderr,"L%d: can't pchar, value out of range", line_number);
    exit(EXIT_FAILURE);
}
printf("%c\n", asc);
}

/**
 * pstr - prints the string 
 * @stack: the pizza stack
 * @line_number: the number to call for the pizza
*/
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *pointer = *stack;

    (void)line_number;
    while (pointer != NULL && pointer->n != 0 && pointer->n >= 0 && pointer->n <= 127)
    {
        putchar(pointer->n);
        pointer = pointer->next;
    }
    putchar('\n');
}

/**
 * rotl - does the magic stuffies
 * @stack: the pizza stack
 * @line_number: the number to call for the pizza
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;
    (void) line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	pointer = *stack;
	while (pointer->next != NULL)
    {
		pointer = pointer->next;
    }

	pointer->next = *stack;
	(*stack)->prev = pointer;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr - does the magic stuffies but to the right
 * @stack: the pizza stack
 * @line_number: the number to call for the pizza
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;
    (void) line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	pointer = *stack;
	while (pointer->next != NULL)
    {
		pointer = pointer->next;
    }

	pointer->next = *stack;
	pointer->next->prev = NULL;
    pointer->prev = NULL;
    (*stack)->prev = pointer;
    (*stack) = pointer;
}

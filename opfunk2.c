#include "monty.h"
/*Following func:*/
/**
 * swap - swaps the top 2 elements
 * @stack: the stacky stack
 * @line_count: you know it already
*/
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *pointer = (*stack)->next;
    if (!stack || !*stack ||(*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next = pointer->next;
    if (!pointer->next)
    {
        pointer->next->prev = *stack;
    }
    pointer->next = *stack;
    (*stack)->prev = pointer;
    pointer->prev = NULL;
    *stack = pointer;
    
}
/**
 * add - adds the data ins together
 * @stack: the stacky stack
 * @line_count: you know it already
*/
void add(stack_t **stack, unsigned int line_number)
{
    int sum = 0;
   if (!stack || !*stack ||(*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack) = (*stack)->next;
    sum =(*stack)->n + (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
/**
 * sub - adds the data ins together
 * @stack: the stacky stack
 * @line_count: you know it already
*/
void sub(stack_t **stack, unsigned int line_number)
{
    int subby = 0;
   if (!stack || !*stack ||(*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack) = (*stack)->next;
    subby =(*stack)->n - (*stack)->prev->n;
    (*stack)->n = subby;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
/**
 * div - adds the data ins together
 * @stack: the stacky stack
 * @line_count: you know it already
*/
void divi(stack_t **stack, unsigned int line_number)
{
    int divoja = 0;
   if (!stack || !*stack ||(*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack) = (*stack)->next;
    divoja =(*stack)->n / (*stack)->prev->n;
    (*stack)->n = divoja;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
/**
 * sub - adds the data ins together
 * @stack: the stacky stack
 * @line_count: you know it already
*/
void muli(stack_t **stack, unsigned int line_number)
{
    int mulholand= 0;
   if (!stack || !*stack ||(*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack) = (*stack)->next;
    mulholand =(*stack)->n * (*stack)->prev->n;
    (*stack)->n = mulholand;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

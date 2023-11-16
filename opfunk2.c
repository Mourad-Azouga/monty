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
        fprintf(stderr, "L%d: can't swap, stack too short", line_number);
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
        fprintf(stderr, "L%d: can't add, stack too short", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack) = (*stack)->next;
    sum =(*stack)->n + (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
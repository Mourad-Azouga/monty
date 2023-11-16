#include "monty.h"
/*This will host push, pall, pint, pop and nop*/
/**
 * push - adds new elements to the stack/queue
 * @stack: the list head
 * @line_number: the line number
*/
void push(stack_t **stack, unsigned int line_number)
{
printf("Value %s number %li\n", stack, line_number);}
/**
 * pall - prints all I guess
 * @stack: the list head
 * @line_number: the line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
    printf("Value %s number %li\n", stack, line_number);
}
/**
 * pint - print int 
  * @stack: the list head
 * @line_number: the line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
printf("Value %s number %li\n", stack, line_number);
}
/**
 * pop
  * @stack: the list head
 * @line_number: the line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
printf("Value %s number %li\n", stack, line_number);
}
/**
 * nop - does nothing
 * @stack: the list head
 * @line_number: the line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
printf("Value %s number %li\n", stack, line_number);
}
#include "monty.h"
/*This will host push, pall, pint, pop and nop*/
/**
 * push - adds new elements to the stack
 * @stack: the list head
 * @line_number: the line number
*/
void push(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
    stack_t *ptr = *stack;

    if (!stack || !*stack){
        exit(EXIT_FAILURE); 
    }
    if (!head){
        head = *stack;
    }
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    (*stack)->next = NULL;
    (*stack)->prev = ptr->prev;
}
/**
 * pall - prints all FROM THE TOP WHICH MEANS LAST ELEMENT ADDED FOR THE STACK AND FIRST FOR THE QUEUE
 * @stack: the list head
 * @line_number: the line number
*/
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    stack_t *ptr = head;
    if (!stack || !*stack){
        exit(EXIT_FAILURE);
    }
    if (!ptr){
        return;
    }
    while (ptr->prev != NULL){
        ptr = ptr->prev; /*this should set the ptr at the head*/
    }
    printf("what's the value of ptr->n in the head before the while? %d\n", ptr->n);
	while(ptr != NULL){	
    	printf("%d\n", ptr->n);
	    ptr = ptr->next;
    }
}
/**
 * pint - print int 
  * @stack: the list head
 * @line_number: the line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
(void) stack;
(void) line_number;
}
/**
 * pop
  * @stack: the list head
 * @line_number: the line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
(void) stack;
(void) line_number;
}
/**
 * nop - does nothing
 * @stack: the list head
 * @line_number: the line number
*/
void nop(stack_t **stack, unsigned int line_number)
{
(void) stack;
(void) line_number;
}

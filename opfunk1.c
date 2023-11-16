#include "monty.h"
/*This will host push, pall, pint, pop and nop*/
/**
 * push - adds new elements to the stack
 * @new_node: the list head
 * @line_number: the line number
 */
void push(stack_t **new_node, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pall - prints all FROM THE TOP WHICH MEANS LAST ELEMENT ADDED FOR THE STACK
 * AND FIRST FOR THE QUEUE
 * @stack: the list head
 * @line_number: the line number
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!stack || !*stack)
		exit(EXIT_FAILURE);
	if (!ptr)
		return;
	while(ptr != NULL)
    {	
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
	stack_t *ptr = *stack;

	if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);

    }
		printf("%d\n", ptr->n);
}
/**
 * pop
 * @stack: the list head
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *pointer;
if (!stack || !*stack)
{
    fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
    exit(EXIT_FAILURE);
}
pointer = *stack;
*stack = pointer->next;
if (*stack != NULL)
    (*stack)->prev = NULL;
free(pointer);
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

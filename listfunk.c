#include "monty.h"
/*This is to handle list dunctions create new node*/
/**
 * create_new_node - Creates a new node that isn't linked to anything
 * @value: the data value that will be associated with the new node
 * @sign: the sign of the new value being treated on its own
 * Return: the pointer to the new node
*/
stack_t* create_new_node(int value, int sign)
{
    stack_t *new;
    new = malloc(sizeof(stack_t));
    if (!new){
        fprintf(stderr, "Malloc error");
        exit(EXIT_FAILURE);
    }
    new->n = value * sign;
    new->next = NULL;
    new->prev = NULL;
    return(new);
}
/**
 * add_queue - because it's a queue we have to fueue, mbloz
 * @hamood: the node to be added
 * @line_n: line counter
*/
void add_queue(stack_t** hamood, __attribute__((unused))unsigned  int line_n)
{
    stack_t *ptr = *hamood;
    if (!hamood || !*hamood){
        exit(EXIT_FAILURE); 
    }
    if (!head){
        head = *hamood;
    }
    while (ptr->prev != NULL){
        ptr = ptr->prev;
    }
    /*This means that the ptr is in the head which is where we want to add our first queue node so that when we pop we pop it at the head*/
    (*hamood)->next = ptr->next;
    (*hamood)->prev = NULL;
}
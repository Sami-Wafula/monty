#include "monty.h"

/**
 * pall - Print all values on the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * @n: variable
 * Return: address of new element
 */

void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new, *h = *stack;

	if (stack == NULL)
	{
		printf("stack is NULL, *stack == NULL, were inside");
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit;
	new->prev = NULL;
	new->n = n;
	new->next = *stack;
	if (*stack)
		h->prev = new;
	*stack = new;
}

/**
 * pop - Removes the top element of the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h)
	{
		*stack = (h)->next;
		free(h);
	}
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: Void
 */

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack, *n;
	
	if (h && h->next)
	{
		n = h->next;
		if (n->next->prev)
			n->next->prev = h;
		h->next = n->next;
		n->prev = NULL;
		n->next = h;
		h->prev = n;
	}
}

#include "monty.h"

/**
 * free_dlistint - frees the singly linked list
 * @head: pointer to list
 * Return: Nothing
 */

void free_stack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}

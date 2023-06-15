#include "lists.h"

/**
 * free_dlistint - function that frees a dlistint_t list.
 * @head: head pointer
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	dlistint_t *fr;

	while (current->next != NULL)
	{
		fr = current->next;
		free(current);
		current = fr;
	}
}

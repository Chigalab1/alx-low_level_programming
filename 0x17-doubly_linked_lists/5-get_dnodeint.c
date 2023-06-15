#include "lists.h"

/**
 * get_dnodeint_at_index - function that returns the nth node of a
 * dlistint_t linked list.
 * @head: pointer to the head of the list
 * @index: index of the nod eto return
 *
 * Return: node at index or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int count = 0;

	while (count < index && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current && count == index)
	{
		return (current);
	}
	else
		return (NULL);
}

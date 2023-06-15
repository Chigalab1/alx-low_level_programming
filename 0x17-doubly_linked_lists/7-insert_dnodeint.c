#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer
 * @idx: index of the list where the node is to be added
 * @n: node data
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h;
	dlistint_t *current = malloc(sizeof(dlistint_t));

	if (idx == 0)
		return (add_dnodeint(h, n));
	while (idx != 1)
	{
		temp = temp->next;
		if (temp == NULL)
			return (NULL);
		idx--;
	}

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	if (current == NULL)
		return (NULL);

	current->n = n;
	current->prev = temp;
	current->next = temp->next;
	temp->next->prev = current;
	temp->next = current;

	return (current);
}

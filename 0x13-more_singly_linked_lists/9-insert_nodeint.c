#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a new node at a
 * given position
 * @head: pointer to the first node
 * @idx: he index of the list where the new node should be added
 * @n: data to insert the new node
 *
 * Return:  the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node;
	listint_t *t = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node || !head)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	i = 0;

	while (t && i < idx)
	{
		if (i == idx - 1)
		{
			new_node->next = t->next;
			t->next = new_node;
			return (new_node);
		}
		else
			t = t->next;
		i++;
	}

	return (NULL);
}

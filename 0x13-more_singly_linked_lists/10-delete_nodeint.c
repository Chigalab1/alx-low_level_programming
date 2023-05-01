#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at index index of a
 * listint_t linked list
 * @head: double pointer
 * @index: index of the node that should be deleted.
 *
 * Return: 1 or -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *t = *head;
	listint_t *cur = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(t);
		return (1);
	}

	for (i = 0; i < index - 1; i++)
	{
		if (!t || !(t->next))
			return (-1);
		t = t->next;
	}
	cur = t->next;
	t->next = cur->next;
	free(cur);

	return (1);
}

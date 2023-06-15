#include "lists.h"

/**
 * delete_dnodeint_at_index - function that deletes the node at index index
 * of a dlistint_t linked list
 * @head: pointer to the first node of the list
 * @index: index of the node to delete
 *
 * Return 1 or -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;

	if (*head == NULL)
		return (-1);
	while (index != 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		temp->prev->next = temp->next;

		if (temp->next != NULL)
			temp->next->prev = temp->prev;
	}
	free(temp);
	return (1);
}

#include "lists.h"
/**
 * add_dnodeint_end - adds a node to the end of a list
 * @head: pointer to the head of the list
 * @n: data of the node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp = malloc(sizeof(dlistint_t));
	dlistint_t *current = *head;

	if (temp == NULL)
		return (NULL);

	temp->n = n;
	temp->next = NULL;

	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;

		current->next = temp;
		temp->prev = current;
	}
	return (temp);
}

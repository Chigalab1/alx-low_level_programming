#include "lists.h"

/**
 * add_dnodeint - unction that adds a new node at the beginning of a
 * dlistint_t list
 * @head: pointer to the head of the list
 * @n: data to add
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *temp = malloc(sizeof(dlistint_t));

	if (temp == NULL)
		return (NULL);

	temp->n = n;
	temp->prev = NULL;

	if (*head != NULL)
	{
		temp->next = *head;
		(*head)->prev = temp;
	}
	else
		temp->next = NULL;

	*head = temp;

	return (temp);
}

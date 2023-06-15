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
	dlistint_t **temp = malloc(sizeof(dlistint_t));
	*temp->prev = NULL;
	*temp->n = n;
	*temp->next = NULL;
	*temp->next = head;
	*head->prev = *temp;
	*head = *temp;

	return (head);
}

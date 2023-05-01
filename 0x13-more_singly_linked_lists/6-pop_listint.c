#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t
 * linked list,  and returns the head node’s data (n)
 * @head: double pointer
 *
 * Return: returns the head node’s data (n) or 0
 */
int pop_listint(listint_t **head)
{
	listint_t *t;
	int numb;

	if (!head || !*head)
		return (0);

	numb = (*head)->n;
	t = (*head)->next;
	free(*head);
	*head = temp;

	return (numb);
}

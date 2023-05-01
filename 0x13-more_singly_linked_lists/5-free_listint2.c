#include "lists.h"

/**
 * free_listint2 - function that frees a linked list
 * @head: double pointer
 */
void free_listint2(listint_t **head)
{
	listint_t *t;

	if (head == NULL)
		return;
	for (; *head != NULL; *head = t)
	{
		t = (*head)->next;
		free(*head);
	}

	*head = NULL;
}

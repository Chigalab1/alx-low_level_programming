#include "lists.h"

/**
 * add_nodeint_end - function that adds a new node at the end of a
 * listint_t list
 * @head: double pointer
 * @n: data to insert the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *t = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	for (; t->next != NULL; t = t->next)
	{
		/*loop until t->next is NULL*/
	}

	t->next = new_node;

	return (new_node);
}

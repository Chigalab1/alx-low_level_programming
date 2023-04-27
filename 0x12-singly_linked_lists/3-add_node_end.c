#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - function that adds a new node at the end of a
 * list_t list
 * @head: double pointer to list_t list
 * @str: string to add in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_n;
	list_t *tmp = *head;
	unsigned int l = 0;

	for (l = 0; str[l]; l++)
		;

	new_n = malloc(sizeof(list_t));
	if (!new_n)
	{
		return (NULL);
	}

	new_n->str = strdup(str);
	new_n->len = l;
	new_n->next = NULL;

	if (*head == NULL)
	{
		*head = new_n;
		return (new_n);
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_n;

	return (new_n);
}

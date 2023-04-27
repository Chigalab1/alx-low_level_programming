#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node -  function that adds a new node at the beginning of a
 * list_t list
 * @head: double pointer to list_t list
 * @str: string to add in the node
 *
 * Return: the address of new element or NUL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_n;
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
	new_n->next = (*head);
	(*head) = new_n;

	return (*head);
}

#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node of a listint_t
 * linked list
 * @head: first node in the linked list
 * @index: index of the node
 *
 * Return: pointer to the node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *t = head;

	for (i = 0, t = head; t && i < index; i++, t = t->next)
	{
		/*loop until t is NULL or i reaches the desired index*/
	}

	return (t ? t : NULL);
}

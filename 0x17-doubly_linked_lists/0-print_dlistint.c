#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint
 * @h: head pointer
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	dlistint_t *temp;

	temp = malloc(sizeof(dlistint_t));
	temp = h;

	if temp == NULL
		return NULL;

	while(temp != NULL)
	{
		printf("%d ", temp->n);
		temp = temp->next;
	}
	return (temp);
}

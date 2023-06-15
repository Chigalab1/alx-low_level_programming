#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint
 * @h: head pointer
 *
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp;
	size_t count = 0;

	temp = malloc(sizeof(dlistint_t));
	temp = h;

	if (temp == NULL)
		return (count);

	while (temp != NULL)
	{
		printf("%d ", temp->n);
		count++;
		temp = temp->next;
	}
	return (count);
}

#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a
 * dlistint list
 * @h: head pointer
 *
 * Return: number of elemets in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *temp;
	size_t count = 0;

	temp = h;

	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

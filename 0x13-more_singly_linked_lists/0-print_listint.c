#include "lists.h"

/**
 * print_listint - function that prints all the elements of a
 * listint_t list
 * @h: listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t numb = 0;

	while (h)
	{
		printf("%d\n", h->n);
		numb++;

		h = h->next;
	}
	return (numb);
}

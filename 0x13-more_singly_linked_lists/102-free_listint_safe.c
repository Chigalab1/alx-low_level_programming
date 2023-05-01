#include "lists.h"

/**
 * free_listint_safe - function that frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t l = 0; /* let l be the length of the free'd list*/
	int a;
	listint_t *t;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		a = *h - (*h)->next;
		if (a > 0)
		{
			t = (*h)->next;
			free(*h);
			*h = t;
			l++;
		}
		else
		{
			free(*h);
			*h = NULL;
			l++;
			break;
		}
	}

	*h = NULL;

	return (l);
}

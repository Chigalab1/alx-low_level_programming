#include "lists.h"

/**
 * find_listint_loop -  function that finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: The address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s = head;
	listint_t *f = head;

	if (!head)
		return (NULL);

	while (s && f && f->next)
	{
		s = s->next;
		f = f->next->next;

		if (f == s)
		{
			for (s = head; s != f; s = s->next, f = f->next)
			{
				/* emty loop*/
			}
			return (f);
		}
	}
	return (NULL);
}

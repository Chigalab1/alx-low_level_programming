#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data (n) of a
 * listint_t linked list
 * @head: first node in the linked list
 *
 * Return: sum of all data in a linked list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *t = head;

	for (t = head; t != NULL; t = t->next)
	{
		sum += t->n;
	}
	return (sum);
}

#include "lists.h"

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - function that counts the number of nodes in a
 * listint_t linked list
 * @head: pointer to the head of the listint_t
 * Return: the number of nodes in the list or 0
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *chi, *gor;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	chi = head->next;
	gor = (head->next)->next;

	for (; gor; chi = chi->next, chi = (chi->next)->next)
	{
		if (chi == gor)
		{
			chi = head;

			for (; chi != gor; chi = chi->next, gor = gor->next)
			{
				nodes++;
			}

			chi = gor->next;

			for (; chi != gor; chi = chi->next)
			{
				nodes++;
			}

			return (nodes);
		}
	}
	return (0);
}

/**
 * print_listint_safe - function that prints a listint_t linked list
 * @head: a pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		while (index < nodes)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			index++;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}

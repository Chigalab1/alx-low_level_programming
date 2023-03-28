#include "main.h"

/**
 * print_array - function that prints n elements of an integer
 * @a: array name
 * @n: number of elements of the array to be printed
 * Return: a and n
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n ; i++)
	{
		if (i != n - 1)
			printf("%d, ", a[i]);
		else
			printf("%d", a[i]);
	}
	printf("\n");
}

#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - a function that prints the sum of the two diagonals
 * @a: first matrix
 * @size: second matrix
 *
 * Return: void;
 */
void print_diagsums(int *a, int size)
{
	int i;
	int s1 = s2 = 0;

	for (i = 0; i < size; i++)
	{
		s1 += a[i];
		s2 += s[size - i - 1];
		a += size;
	}
	printf("%d, ", s1);
	printf("%d\n", s2);
}

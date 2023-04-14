#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * array_range - function that creates arrays of int
 * @min: minimum value
 * @max: max value
 *
 * Return: a pointer or NULL
 */
int *array_range(int min, int max)
{
	int a;
	int i;
	int *ptr;

	a = 0;

	if (min > max)
		return (NULL);
	a = ((max + 1) - min);

	ptr  = malloc(a * sizeof(int));

	if (ptr == NULL)
		return (NULL);
	for  (i = 0; i < a; i++)
	{
		*(ptr + i) = min + i;
	}

	return (ptr);
}

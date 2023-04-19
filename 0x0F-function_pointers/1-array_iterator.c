#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - executes a function parameter on each element of an array
 * @array: array of integers
 * @size: number of elements to print
 * @action: pointer to print
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL)
		return;
	if (action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}

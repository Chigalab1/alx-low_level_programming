#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc -  function that reallocates a memory block using malloc and free
 * @ptr: a pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 *
 * Return: a pointer to the mem block or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *r;
	unsigned int i = 0;

	if (new_size == old_size)
		return (ptr);
	if ((new_size == 0) && (ptr != NULL))
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		r = malloc(new_size);
		if (r == NULL)
			return (NULL);
	}

	if (new_size > old_size && (ptr != NULL))
	{
		r = malloc(new_size);

		if (r == NULL)
			return (r);
		while (i < old_size)
		{
			r[i] = *((char *)ptr + 1);
			i++;
		}
		free(ptr);
	}
	return (r);
}

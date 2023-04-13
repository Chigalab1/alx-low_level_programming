#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * _calloc -  function that allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of bytes
 *
 * Return: NULL or pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i = 0;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	ptr = malloc(nmemb * size);

	if (p == NULL)
	{
		return (NULL);
	}
	while (i < (nmemb * size))
	{
		*((char *)(ptr) + i) = 0;
		i++;
	}

	return (ptr);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - a function that creates an array of chars
 * @size: integer size
 * @c: character
 *
 * Return: NULL or a pointer
 */
char *create_array(unsigned int size, char c)
{
	char *buffer;
	unsigned int i = 0;

	buffer = malloc(size * sizeof(char));
	if (size == 0 || buffer == NULL)
		return (NULL);
	while (i < size)
	{
		buffer[i] = c;
		i++;
	}
	return (buffer);
}

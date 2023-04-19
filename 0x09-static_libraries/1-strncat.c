#include "main.h"

/**
 * _strncat - function that concatenates two strings
 * @dest: destination character
 * @src: source
 * @n: dest string
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, destlen = 0;

	while (dest[index++])
		destlen++;

	for (index = 0; src[index] && index < n; index++)
		dest[destlen++] = src[index];

	return (dest);
}

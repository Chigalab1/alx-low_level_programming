#include "main.h"

/**
 * _memcpy - function that copies memory area
 * @dest: destination
 * @src: source
 * @n: number of bytes
 *
 * Return: memory copied
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = 0;
	int j = n;

	for (; i < j; i++)
	{
		dest[i] = src[i];
		n--;
	}
	return (dest);
}

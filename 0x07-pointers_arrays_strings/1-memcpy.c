#include "main.h"
/**
 * _memcpy - function that copies memory area
 * @dest: a pointer to the destination mem block
 * @src: a pointer to the source mem block
 * n: number of bytes to be copied
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *i = dest;
	char *j = src;

	while (n--)
	{
		*i++ = *j++;
	}
	return (dest);
}

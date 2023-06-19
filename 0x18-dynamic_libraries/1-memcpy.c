#include "main.h"
/**
 * _memcpy - function that copies memory area
 * @dest: a pointer to the destination mem block
 * @src: a pointer to the source mem block
 * @n: number of bytes to be copied
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = 0;
	int j = n;

	for (i = 0; j > i; i++)
	{
		dest[i] = src[i];
		n--;
	}
	return (dest);
}

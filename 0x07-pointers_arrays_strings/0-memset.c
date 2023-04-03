#include "main.h"
/**
 * _memset - a function that fills memory with a constant byte
 * @s: a pointer to the memory block to be filled
 * @n: number of bytes
 * @b: value to be set
 *
 * Return: a pointerto the memory s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned char *i = s;

	while (n--)
	{
		*i++ = unsigned char b;
	}
	return (s);
}


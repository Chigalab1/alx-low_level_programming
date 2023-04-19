#include "main.h"

/**
 * _memset - a function that fills a value in a block of memory
 * @s: starting address of mem
 * @b: desired value
 * @n: number of bytes
 *
 * Return: s
 */
char *_memsrt(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}

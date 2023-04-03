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
	int i = 0;

	for (i = 0, n > i, i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}

#include "main.h"

/**
 * _strlen - function that returns a string length
 * @s: string
 *
 * Return: string length
 */
int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}

	return (l);
}

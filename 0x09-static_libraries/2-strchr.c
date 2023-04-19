#include "main.h"
#include <stddef.h>

/**
 * _strchr - function that searches for occurance of char
 * @s: pointer to character
 * @c: input char
 * Return: 0
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s [i] >= '\0'; i++)
	{
		if (s[i] ==c)
			return (&s[i]);
	}
	return (0);
}

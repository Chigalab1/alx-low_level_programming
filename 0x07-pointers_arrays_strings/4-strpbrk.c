#include "main.h"

/**
 * _strpbrk - a function that searches a string for any of a set of bytes
 * @s: first string
 * @accept: second string
 *
 * Return: a pointer
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0;
	int j;
	char *k;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (accept[j] == s[i])
			{
				k = &s[i];
				return (k);
			}
			j++;
		}
		i++;
	}

	return (0);
}

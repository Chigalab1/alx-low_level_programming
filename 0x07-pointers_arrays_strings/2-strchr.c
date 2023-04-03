#include "main.h"

/**
 * _strchr - function that lovates a string
 * @s: pointer to a string
 * @c: charcter
 *
 * Return: char or NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; i != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (i);
		}
		else
			return (NULL);
	}

	return (i);
}

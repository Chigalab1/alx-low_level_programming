#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - a function that returns a pointer to a newly allocated space
 * @str: character
 *
 * Return: NULL
 */
char *_strdup(char *str)
{
	char *s;
	int i;
	int j;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		s = malloc(sizeof(char) * (i + 1));
	}
	if (s == NULL)
		return (NULL);

	for (j = 0; str[j]; j++)
	{
		s[j] = str[j];
	}
	return (s);
}

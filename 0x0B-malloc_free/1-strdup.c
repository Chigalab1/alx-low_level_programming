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
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	
	s = malloc(sizeof(char) * (i + 1));

	if (s == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{
		s[i] = str[i];
	}
	s[i] = str[i];
	return (s);
}

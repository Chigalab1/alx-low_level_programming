#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * strtow -  function that splits a string into words
 * @str: string to be splitted
 *
 * Return: pointer to an array
 */
char **strtow(char *str)
{
	char **p;
	int wc = 0;
	int str_len = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	if (str == 0)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ' && str[i + 1] == ' ')
			wc++;
		if (str[i] != ' ' && str[i + 1] == '\0')
			wc++;
		i++;
	}
	if (wc == 0)
		return (NULL);
	p = malloc(sizeof(char *) * (wc + 1));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (i = 0, j = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			str_len = 0;
		if (str[i] != ' ')
			str_len++;
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			p[j] = malloc(sizeof(char) * str_len + 1);
			if (p[j] == NULL)
			{
				for ( ; j >= 0; j--)
					free(p[j]);
				free(p);
				return (NULL);
			}
			j++;
		}
	}
	for (i = 0, j = 0, k = 0; str[i]; i++)
	{
		if (str[i] != ' ' && str[i] != '\0' && j < wc && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			p[j][k] = str[i];
			k++;
			p[j][k] = '\0';
			j++;
			k = 0;
		}
		else if (str[i] != ' ' && str[i] != '\0')
		{
			p[j][k] = str[i];
			k++;
		}
	}
	p[wc] = NULL;
	return (p);
}

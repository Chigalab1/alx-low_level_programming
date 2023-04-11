#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - function that concatenates two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	int len1;
	int len2;
	char *ss;

	if (s1 == NULL || s2 == NULL)
	{
		return ("");
	}
	int i = 0;
	int j = 0;

	while (s1[i] != '\0')
		i++;
	{
		len1++;
	}
	while (s2[j] != '\0')
		j++;
	{
		len2++;
	}

	ss = malloc((len1 + (len2 + 1)) * sizeof(char));

	if (ss == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		ss[i] = s1[i];
	for (j = 0; s2[j] != '\0'; j++)
		ss[i + j] = s2[j];

	ss[i + j] = ('\0');

	return (ss);
}

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
	int i = 0;
	int j = 0;
	char *ss;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	ss = malloc(1 + (sizeof(char) * i) + (sizeof(char) * j));
	if (ss == NULL)
		return (NULL);
	for (i = 0; s1[i]; i++)
	{
		ss[i] = s1[i];
	}
	for (j = 0; s2[j]; j++)
	{
		ss[i] = s2[j];
		i++;
	}
	ss[i] = s2[j];
	return (ss);
}

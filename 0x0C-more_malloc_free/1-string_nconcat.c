#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * _strlen - calculate and return string length
 * @string: string to check length
 *
 * Return: Length of string
 */
int _strlen(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)

	return (i);
}
/**
 * string_nconcat -  function that concatenates two strings
 * @s1: argument 1
 * @s2: argument 2
 * @n: number of byes
 * Return:a pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	int num = n;
	int l;
	int i = 0;
	int j = 0;

	num = n;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (num < 0)
		return (NULL);
	if (num >= _strlen(s2))
		num = _strlen(s2);

	l = _strlen(s1) + num + 1;

	p = malloc(sizeof(*p) * l);
	if (p == NULL)
		return (NULL);

	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (j < num)
	{
		p[i +j] = s2[j];
		j++;
	}
	p[i + j] = '\0';

	return (p);
}

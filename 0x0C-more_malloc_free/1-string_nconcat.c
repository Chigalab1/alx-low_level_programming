#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * string_nconcat -  function that concatenates two strings
 * @s1: argument 1
 * @s2: argument 2
 *
 * Return:a pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	size_t ss1 = strlen(s1);
	size_t ss2 = strlen(s2);
	size_t size = (ss1 + n + 1) * sizeof(char);

	if (n >= ss2)
	{
		n = ss2;
	}

	char *result = malloc(size);
	memcp

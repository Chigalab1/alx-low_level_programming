#include "main.h"

/**
 * _strstr - a function that locates a substring
 * @haystack: string to be searched
 * @needle: string to be located
 *
 * Return: a pointer or Null
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*needle == '\0')
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 1; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (needle[j] == '\0')
				return (&haystack[i]);
		}
	}
	return (0);
}

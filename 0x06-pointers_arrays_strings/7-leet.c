#include "main.h"
/**
 * leet - funcition that encodes a string
 * @str: string to be encode
 * Return: returns encoded string
 */

char *leet(char *str)
{
	int i;
	int j;

	char s1[] = "aAeEoOtTlL";
	char s2[] = "4433007711";

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		for (j = 0 ; j < 10; j++)
		{
			if (str[i] == s1[j])
			{
				str[i] = s2[j];
			}
		}
	}
	return (str);
}

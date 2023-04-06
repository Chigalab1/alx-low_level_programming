#include "main.h"

int check_pal(char *s, int i, int j);
int _strlen_recursion(char *s);

/**
 * is_palindrome - function that checks if a string is palindrome
 * @s: string to reverse
 *
 * Return: 1 or 0
 */
int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);
	return (check_pal(s, 0, _strlen_recursion(s)));
}
/**
 * _strlen_recursion - returns lenght of a string
 * @s: length of string to be determined
 *
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
/**
 * check_pal -check for palindrome recursion
 * @s: string to check
 * @i: int assigned
 * @j: string length
 *
 * Return: 1 or 0
 */

int check_pal(char *s, int i, int j)
{
	if (*(s + i) != *(s + j - 1))
		return (0);
	if (i >= j)
		return (1);
	return (check_pal(s, i + 1, j - 1));
}

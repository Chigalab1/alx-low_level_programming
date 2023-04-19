#include "main.h"

/**
 * _isalpha - function that checks for alphabets
 * @c: char to check
 * Return: 1 or 0
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

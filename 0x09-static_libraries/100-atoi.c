#include "main.h"

/**
 * _atoi - function that converts string to int
 *
 * @s: parameter
 * Return: int
 */
int _atoi(char *s)
{
	int a = 1;
	int b = 0;
	unsigned int r = 0;

	while (!(s[b] <= '9' && s[b] >= '0') && s[b] != '\0')
	{
		if (s[b] == '-')
			a *= -1;
		b++;
	}
	while (s[b] <= '9' && (s[b] >= '0' && s[b] != '\0'))
	{
		r = (r * 10) + (s[b] - '0');
		b++;
	}
	r *= a;
	return (r);
}

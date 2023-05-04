#include "main.h"
#include <stddef.h>

/**
 * print_binary - function that prints the binary representation of a number
 * @n: parameter to print binary
 */
void print_binary(unsigned long int n)
{
	int i;
	int c = 0;
	size_t num;

	for (i = 63; i >= 0; i--)
	{
		num = n >> i;

		if (num & 1)
		{
			_putchar('1');
			c++;
		}
		else if (c)
			_putchar('0');
	}
	if (!c)
		_putchar('0');
}

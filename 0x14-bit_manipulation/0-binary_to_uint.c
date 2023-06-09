#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - function that converts binary to unsigned int
 * @b: string of binary numbers
 *
 * Return: the converted number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	size_t decimal = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		decimal = 2 * decimal + (b[i] - '0');
	}
	return (decimal);
}

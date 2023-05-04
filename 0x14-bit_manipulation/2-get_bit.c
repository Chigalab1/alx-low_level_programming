#include "main.h"

/**
 * get_bit - function that returns the value of a
 * bit at a given index
 * @index: index of the bit
 * @n: integer from which to extract the bit
 *
 * Return:  the value of the bit at index index or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	val;

	if (index > 63)
	{
		return (-1);
	}
	val = (n >> index) & 1;

	return (val);
}

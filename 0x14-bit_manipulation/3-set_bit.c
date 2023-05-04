#include "main.h"

/**
 * set_bit - function that sets the value of a bit
 * to 1 at a given index
 * @n: pointer to unsigned long int
 * @index: position of bit
 *
 * Return: 1 or -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int in = index;

	if (in > 63)
		return (-1);

	*n = ((1UL << in) | *n);

	return (1);
}

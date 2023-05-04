#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would
 * need to flip to get from one number to another
 * @n: unsigned int parameter
 * @m: unsigned int parameter
 *
 * Return: number of bit to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i;
	int c = 0;
	unsigned long int num;
	unsigned long int exc = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		num = exc >> i;
		if (num & 1)
			c++;
	}
	return (c);
}

#include "main.h"
/**
 * swap_int - to swap two values
 * @a: the dirst value
 * @b: the second value
 * Return: 0
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

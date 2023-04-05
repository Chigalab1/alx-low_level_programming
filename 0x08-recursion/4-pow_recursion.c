#include "main.h"

/**
 * _pow_recursion - function that returns x raised to power y
 * @x: base number
 * @y: power being raised
 *
 * Return: x raised to power y or -1
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	if (y == 1)
		return (x);
	return (x * _pow_recursion(x, y - 1));
}

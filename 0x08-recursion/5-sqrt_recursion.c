#include "main.h"

/**
 * _sqrt_recursion - returns the square root if an int
 * @n: number
 * @i: square root of int
 *
 * Return: square root or -1
 */
int square(int n, int i);
int _sqrt_recursion(int n)
{
	return (square(n, 1));
}

/**
 *square - function that finds square root
 *@n: number@i: square root of int
 *@i: square root of int
 *
 * Return: integer
 */
int square(int n, int i)
{

	if (i * i == n)
		return (i);
	else if (i * i < n)
		return (square(n, i + 1));
	else
		return (-1);
}

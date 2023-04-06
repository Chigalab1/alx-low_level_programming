#include "main.h"

int actual_prime(int n, int j);
/**
 * is_prime_number - function that checks for prime number
 * @n: number to check
 *
 * Return: 1 or 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, n - 1));
}
/**
 * actual_prime - checks i a number is prime recursively
 * @n: number to check
 * @j: int assigned
 *
 * Return: 1 or 0
 */
int actual_prime(int n, int j)
{
	if (j == 1)
		return (1);
	if (n % j == 0 && j > 0)
		return (0);
	return (actual_prime(n, j - 1));
}

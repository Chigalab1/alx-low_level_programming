#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - adds two numbers
 * @a: parameter 1
 * @b: parameter 2
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts b from a
 * @a: parameter 1
 * @b: parameter 2
 *
 * Return: (b - a)
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two numbers
 * @a: parameter 1
 * @b: parameter 2
 *
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - disision of two numbers
 * @a: parameter 1
 * @b: parameter 2
 *
 * Return: division of a and b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - remainder of the division of two numbers
 * @a: parameter 1
 * @b: parameter 2
 *
 * Return: remainder of division of a number
 */
int op_mod(int a, int b)
{
	return (a % b);
}

#include "main.h"
/**
 * print_triangle - print a triangle folloewed by a new line
 * @size: size of the triangle
 * Return: void
 */
void print_triangle(int size)
{
	int i = 1, j;

	while (i <= size && size > 0)
	{
		j = 0;
		while (j < size - i)
		{
			_putchar(' ');
			j++;
		}
		j = 0;
		while (j < i)
		{
			_putchar('#');
			j++;
		}

		_putchar('\n');
		i++;
	}
	if (i == 1)
		_putchar('\n');
}

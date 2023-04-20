#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_numbers - function that prints numbers, followed by a new line
 * @seperator: string to be printed
 * @n: integers
 *
 * Return: 0
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list j;

	va_start(j, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(j, int));
		if (i < n -1 && seperator != NULL)
			printf("%s", seperator);
	}
	printf("\n");


	va_end(j);
}

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * print_strings - function that prints strings, followed by a new line
 * @separator: string to be printed
 * @n: string size
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *ptr;
	va_list s;

	if (separator == NULL)
		separator = "";

	va_start(s, n);

	for (i = 0; i < n; i++)
	{
		ptr = va_arg(s, char *);

		if (ptr == NULL)
			ptr = "(nil)";
		printf("%s", ptr);

		if (i < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(s);
}

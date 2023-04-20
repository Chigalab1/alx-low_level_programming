#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * print_all - function that prints anything
 * @format: arguments
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	unsigned int i;
	va_list j;
	char *k;
	char *m;

	va_start(j, format);

	m = "";

	i = 0;
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", m, va_arg(j, int));
				break;
			case 'i':
				printf("%s%c", m, va_arg(j, int));
				break;
			case 'f':
				printf("%s%f", m, va_arg(j, double));
				break;
			case 's':
				k = va_arg(j, char *);
				if (k == NULL)
				{
					k = "(nil)";
				}
				printf("%s%s", m, k);
				break;
			default:
				i++;
				continue;
		}
		m = ", ";
		i++;
	}

	printf("\n");
	va_end(j);
}

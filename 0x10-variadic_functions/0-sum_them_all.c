 #include <stdarg.h>
/**
 * sum_them_all - function that returns the sum of all its parameters
 * @n: argument size
 *
 * Return: integer
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int s = 0;
	unsigned int i;
	va_list j;

	if (n == 0)
		return (0);

	va_start(j, n);

	for (i = 0; i < n; i++)
	{
		s = s + va_arg(j, int);
	}
	va_end(j);

	return (s);
}

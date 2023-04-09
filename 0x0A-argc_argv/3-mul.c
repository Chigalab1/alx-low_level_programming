#include <stdio.h>
#include "main.h"

/**
 * _atoi - functio that converts string to int
 * @s: string
 *
 * Return: 0
 */
int _atoi(char *s)
{
	int i, j, k, length, m, digit;

	i = 0;
	j = 0;
	k = 0;
	length = 0;
	m = 0;
	digit = 0;

	while (s[length] != '\0')
		length++;

	while (i < length && m == 0)
	{
		if (s[i] == '-')
			++j;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (j % 2)
				digit = -digit;
			k = k * 10 + digit;
			m = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			m = 0;
		}
		i++;
	}

	if (m == 0)
		return (0);

	return (k);
}

/**
 * main - a program that multiplies two numbers
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: 0 on success or 1 on error
 */
int main(int argc, char *argv[])
{
	int result, n1, n2;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	n1 = _atoi(argv[1]);
	n2 = _atoi(argv[2]);
	result = n1 * n2;

	printf("%d\n", result);

	return (0);
}

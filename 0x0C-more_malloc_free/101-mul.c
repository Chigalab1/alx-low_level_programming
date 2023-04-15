#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_len - Finds the length of a string.
 * str: The string to be measured.
 *
 * Return: The length of the string.
 */
int find_len(char *str)
{
	int l = 0;

	while (*str++)
		l++;

	return (l);
}

/**
 * create_xarray - craete an array of charges abd initialize of to l
 * @size: size of array
 *
 * Return: pointer fo the array
 */
char *create_xarray(int size)
{
	char *array;
	int idx = 0;

	array = malloc(sizeof(char) * size);

	if (array == NULL)
		exit(98);

	while (idx < (size - 1))
	{
		array[idx] = 'x';
		idx++;
	}
	array[idx] = '\0';

	return (array);
}
/**
 * iterate_zeroes - iterates through a string of numbers containing leading zeroes
 * @str: strings of numbers
 *
 * Return: a pointer
 */
char *iterate_zeroes(char *str)
{
	while (*str && *str == '0')
		str++;

	return (str);
}
/**
 * get_digit - function that converts digit character to int
 * @c: character
 *
 * Return: int
 */
int get_digit(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}
	return (digit);
}
/**
 * get_prod - function that multiplies string of numbers by a digit
 * @prod: buffer
 * @mult: string of numbers
 * @digit: digit
 * @zeroes: leading zeroes
 */
void get_prod(char *prod, char *mult, int digit, int zeroes)
{
	int multlen = 0;
	int num = 0;
	int t = 0;

	multlen = find_len(mult) - 1;
	mult = mult + multlen;

	while (*prod)
	{
		*prod = 'x';
		prod++;
	}

	prod--;

	while (zeroes--)
	{
		*prod = '0';
		prod--;
	}

	for (; multlen >= 0; multlen--, mult--, prod--)
	{
		if (*mult < '0' || *mult > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*mult - '0') * digit;
		num = num + t;
		*prod = (num % 10) + '0';
		t = num / 10;
	}
	if (t)
		*prod = (t % 10) + '0';
}
/**
 * add_nums - add numbers stored in two strings
 * @finalp: buffer storing the final product
 * @nextp: next product to be added
 * @next_len: length of next_prod
 *
 * Return: void
 */
void add_nums(char *finalp, char *nextp, int next_len)
{
	int num = 0;
	int t = 0;

	while (*(finalp + 1))
		finalp++;

	while (*(nextp + 1))
		nextp++;

	for (; *finalp != 'x'; finalp--)
	{
		num = (*finalp - '0') + (*nextp - '0');
		num += t;
		*finalp = (num % 10) + '0';
		t = num / 10;

		nextp--;
		next_len--;
	}
	for (; next_len >= 0 && *nextp != 'x'; next_len--)
	{
		num = (*nextp - '0');
		num = num + t;
		*finalp = (num % 10) + '0';
		t = num / 10;

		finalp--;
		nextp--;
	}

	if (t)
		*finalp = (t % 10) + '0';
}

/**
 * main - a function that multiplies two ppositive numbers
 * @argv: number of arguments
 * @argc: argument count
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *finalp;
	char *nextp;
	int size = 0;
	int idx = 0;
	int digit = 0;
	int zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = iterate_zeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = iterate_zeroes(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = find_len(argv[1]) + find_len(argv[2]);
	finalp = create_xarray(size + 1);
	nextp = create_xarray(size + 1);

	for (idx = find_len(argv[2]) - 1; idx >= 0; idx--)
	{
		digit = get_digit(*(argv[2] + idx));
		get_prod(nextp, argv[1], digit, zeroes++);
		add_nums(finalp, nextp, size - 1);
	}

	for (idx = 0; finalp[idx]; idx++)
	{
		if (finalp[idx] != 'x')
			_putchar(finalp[idx]);
	}
	_putchar('\n');

	free(nextp);
	free(finalp);

	return (0);
}

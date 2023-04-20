#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"
/**
 * main - program that performs simple operation
 * @argc: argument count
 * @argv: array of pointers to the argument
 *
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int num1;
	int num2;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	if (get_0p_func(op) == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	if (op[1] != '\0')
	{
		printf("Error\n");
		exit(98);
	}

	if (*op == '/' && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}
	if (*op == '%' && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", get_0p_func(op)(num1, num2));
	return (0);
}

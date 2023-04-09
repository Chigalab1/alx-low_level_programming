#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: 0 on succes or 1 on error
 */
int main(int argc, char *argv[])
{
	int n, i, result;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	n = atoi(argv[1]);
	result = 0;

	if (n < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < 5 && n >= 0; i++)
	{
		while (n >= coins[i])
		{
			result++;
			n = n - coins[i];
		}
	}

	printf("%d\n", result);
	return (0);
}

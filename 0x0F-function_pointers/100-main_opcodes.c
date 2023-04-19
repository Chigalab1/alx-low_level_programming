#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that prints opcode
 * @argc: argument count
 * @argv: array of argument
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;
	int b;
	char *j;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	b = atoi(argv[1]);

	if (b < 0)
	{
		printf("Error\n");
		exit(2);
	}

	j = (char *)main;

	i = 0;

	while (i < b)
	{
		if (i == b - 1)
		{
			printf("%02hhx\n", j[i]);
			break;
		}
		printf("%02hhx ", j[i]);
		i++;
	}
	return (0);
}

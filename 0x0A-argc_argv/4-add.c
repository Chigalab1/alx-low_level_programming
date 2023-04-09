#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - Entry point
 * @argc: number of arg
 * @argv: array of arg
 *
 * Return: 0 or Error
 */
int main(int argc, char *argv[])
{
	int k, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
	}
	if (argc > 1)
	{
		for (k = 1; k < argc; k++)
		{
			int l;

			for (l = 0; argv[k][l] != '\0'; l++)
			{
				if (!isdigit(argv[k][l]))
				{
					printf("Error\n");
					return (1);
				}
			}
			sum = sum + atoi(argv[k]);
		}
		printf("%d\n", sum);
	}
	return (0);
}

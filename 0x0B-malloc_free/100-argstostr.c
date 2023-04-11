#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr -  function that concatenates all the arguments of your program
 * @ac: argument length
 * @av: argument value
 *
 * Return: NULL
 */
char *argstostr(int ac, char **av)
{
	int i;
	int j;
	int k = 0;
	int t = 0;
	char *p;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
		for (j = 0; av[i][j]; j++)
			t++;
	p = (char *) malloc(sizeof(char) * (t + ac + 1));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++, k++)
			p[k] = av[i][j];
		p[k] = '\n';
		k++;
	}
	p[k] = '\0';
	return (p);
}

#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
 * alloc_grid - function thats returns pointer to 2d array
 * @width: rows
 * @height: column
 *
 * Return: pointer or NULL
 */
int **alloc_grid(int width, int height)
{
	int **p;
	int i = 0;
	int j;

	if (width <= 0 || height > INT_MAX)
		return (NULL);
	if (width > INT_MAX || height > INT_MAX)
		return (NULL);
	p = malloc(height * sizeof(int *));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	while (i < height)
	{
		p[i] = malloc(width * sizeof(int));
		if (p[i] == NULL)
		{
			for ( ; i >= 0; i--)
				free(p[i]);
			free(p);
			return (NULL);
		}
		i++;
	}
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			p[i][j] = 0;
	return (p);
}

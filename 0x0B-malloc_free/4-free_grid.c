#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * free_grid - a function that frees a 2 dimensional grid
 * @grid: pointer to a pointer int
 * @height: column
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i = 0;

	if (grid == NULL || height <= 0)
		return;
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

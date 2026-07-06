#include "main.h"
#include <stdlib.h>

/**
* free_grid - Free all memory for a 2D array
* @grid: The array to free
* @height: The height of the array
* Return: None
*/

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
	{
		return;
	}

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

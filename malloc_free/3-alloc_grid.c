#include "main.h"
#include <stdlib.h>

/**
* alloc_grid - Create a 2D array of given size
* @width: Size of internal arrays
* @height: Size of first array
* Return: Pointeur to the 2D array
*/

int **alloc_grid(int width, int height)
{
	int **arr;
	int i;
	int *temp;

	if (width <= 0 || height <= 0)
		return (NULL);

	arr = malloc(sizeof(*arr) * height);

	for (i = 0; i < height; i++)
	{
		temp = malloc(sizeof(*arr) * width);
		arr[i] = &temp;
	}

	return (arr);
}

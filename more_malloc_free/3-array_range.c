#include "main.h"
#include <stdlib.h>

/**
* array_range - Create an array of integer
* @min: Starting value for the array (include)
* @max: Ending value for the array (include)
* Return: Pointer to the newly created array
*/

int *array_range(int min, int max)
{
	int *arr;
	int i;
	int size = (max - min) + 1;

	if (min > max)
		return (NULL);

	arr = malloc(sizeof(*arr) * size);

	for (i = 0; i <= size; i++)
	{
		arr[j] = min + i;
	}

	return (arr);
}

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
	int j = 0;

	if (min > max)
		return (NULL);

	arr = malloc(sizeof(*arr) * max);

	for (i = min; i <= max; i++)
	{
		arr[j] = i;
		j++;
	}

	return (arr);
}

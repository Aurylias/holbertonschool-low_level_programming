#include "function_pointers.h"

/**
* int_index - Search for an interger
* @array: The array it self
* @size: number of element in the array
* @cmp: Function pointer to compare values
* Return: The index for which cmp doesn't return 0
*/

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if(cmp(array[i]))
		{
			return (i);
		}
	}

	return (-1);
}

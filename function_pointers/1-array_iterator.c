#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>

/**
* array_iterator - Execute a given fonction on each element of an array
* @array: Array on which we execute an action
* @size: Size of the array
* @action: Function to execute
* Return: None
*/

void array_iterator(int *array, size_t size, void (*action)(int))
{
	int i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}

#include "main.h"
#include <stdlib.h>

/**
* create_array - Create an array of char
* @size: Size of the array
* @c: Char to put int the array
* Return: A pointer to the array
*/

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	if (size == 0)
		return (NULL);

	str = malloc(sizeof(*str) * size);

	for (i = 0; i < size; i++)
	{
		str[i] = c;
	}

	return (str);
}

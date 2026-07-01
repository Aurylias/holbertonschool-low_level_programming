#include "main.h"

/**
 * _strlen - Return the length of a string with \0
 * @s: Pointer of a string
 * Return: The size of a string
 */

int _strlen(char *s)
{
	char *last = s;

	while (*last++)
	{

	}

	return (last - s - 1);
}

/**
 * _strncat - Add char to dest until n index
 * @dest: First string to add
 * @src: Second string to add
 * @n: The index of src to reach
 * Return: A string concateneted
 */

char *_strncat(char *dest, char *src, int n)
{
	int d_len = _strlen(dest);
	int i;
	int j = 0;

	for (i = d_len; src[j] != src[n]; i++)
	{
		dest[i] = src[j];
		j++;
	}

	return (dest);
}

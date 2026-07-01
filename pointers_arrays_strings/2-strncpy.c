#include "main.h"

/**
 * _strncpy -
 * @dest: First string to add
 * @src: Second string to add
 * @n: The index of src to reach
 * Return: A string concateneted
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (x = 0; i < n && src[i] != '\0'; x++)
	{
		dest[i] = src[i];
	}
}

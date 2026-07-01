#include "main.h"

/**
 * _strncpy - Copy a string in an other
 * @dest: First string to add
 * @src: Second string to add
 * @n: The index of src to reach
 * Return: A string concateneted
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (x = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
}

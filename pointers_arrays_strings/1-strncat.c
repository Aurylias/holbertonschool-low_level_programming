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
 * _strncat - 
 * @dest:
 * @src:
 * @n:
 * Return: 
 */

char *_strncat(char *dest, char *src, int n)
{
	int d_len = _strlen(dest);
	int s_len = _strlen(src);
	int i;
	int j = 0;

	for (i = d_len; i <= (d_len + (s_len - n)); i++)
	{
		dest[i] = src[j];
		j++;
	}

	return (dest);
}
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
 * _strcat - Add two string together
 * @dest: First string to add
 * @src: Second string to add
 * Return: Added strings
 */

char *_strcat(char *dest, char *src)
{
	int d_len = _strlen(dest);
	int s_len = _strlen(src);
	int i;
	int j = 0;

	for (i = d_len; i <= (d_len + s_len); i++)
	{
		dest[i] = src[j];
		j++;
	}

	return (dest);
}

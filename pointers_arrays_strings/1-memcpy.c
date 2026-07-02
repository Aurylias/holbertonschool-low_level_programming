#include "main.h"

/**
 * _memcpy - Copies memory area
 * @dest: String to copy to
 * @src: String  to copy from
 * @n: Number of bytes to copy
 * Return: Return a pointer to a char
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;
	int fill = n;

	if (fill > 0)
	{
		for (i = 0; i < fill; i++)
			dest[i] = src[i];
	}

	return (s);
}

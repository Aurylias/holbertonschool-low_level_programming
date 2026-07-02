#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 * @s: String to fill
 * @b: Value of the byte
 * @n: Index for the value
 * Return: Pointer to a char
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
			s[i] = b;
	}

	return (s);
}
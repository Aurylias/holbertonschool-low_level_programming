#include "main.h"

int _strlen(char *s);

/**
 * _strlen - Return the length of a string
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
 * rev_string
 * @s: Test
 * Return: None
 */

void rev_string(char *s)
{
	int i = _strlen(s) - 1;

	for (; i >= 0; i--)
	{
		_putchar(s[i]);
	}
}

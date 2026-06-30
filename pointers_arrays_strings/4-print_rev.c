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
 * print_rev - Print a string in reverse
 * @s: Pointer to a string
 * Return: None
 */

void print_rev(char *s)
{
	int i = _strlen(s);

	for (; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar(s[0]);
}

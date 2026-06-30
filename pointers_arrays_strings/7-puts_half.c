#include "main.h"

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
 * puts_half - Print half of a string
 * @str: Pointer to a string
 * Return: None
 */

void puts_half(char *str)
{
	int len = _strlen(str);
	int i;
	int half = len / 2;

	if (len % 2 != 0)
	{
		half++;
	}

	for (i = half; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar(10);
}

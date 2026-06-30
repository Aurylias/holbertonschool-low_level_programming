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
 * puts2 - Print 
 * @str: Pointer to a char
 * Return: None
 */

void puts2(char *str)
{
	int len = _strlen(str);
	int i;

	for (i = 0; i <= len; i + 2)
	{
		_putchar(str[i]);
	}
	_putchar(10);
}

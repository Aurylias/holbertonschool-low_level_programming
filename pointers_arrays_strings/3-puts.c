#include "main.h"

/**
 * _puts - Print a string
 * @str: Pointer to a string
 * Return: None
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar(10);
}

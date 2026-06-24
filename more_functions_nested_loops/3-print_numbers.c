#include "main.h"

/**
 * print_numbers - Print 0123456789
 * Return: None
 */

void print_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		_putchar(i + '0');
	}

	_putchar('\n');
}

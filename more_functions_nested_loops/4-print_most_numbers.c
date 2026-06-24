#include "main.h"

/**
 * print_most_numbers - Print 0123456789 but not 2 and 4
 * Return: None
 */

void print_most_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		if (i == 2 || i == 4)
		{
			_putchar(i + '0');
		}
	}

	_putchar('\n');
}

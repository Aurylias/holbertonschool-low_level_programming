#include "main.h"

/**
 * more_numbers - Print 0123456789 10 times
 * Return: None
 */

void print_line(int n)
{
	int to_print;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (to_print = 0; to_print <= n; to_print++)
		{
			_putchar('_');
		}

		_putchar('\n');
	}
}

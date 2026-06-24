#include "main.h"

/**
 * print_line - Draw a line in the terminal
 * @n: Number of _ to print
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
		for (to_print = 0; to_print < n; to_print++)
		{
			_putchar('_');
		}

		_putchar('\n');
	}
}

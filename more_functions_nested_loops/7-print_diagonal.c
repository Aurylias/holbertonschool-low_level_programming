#include "main.h"

/**
 * print_diagonal - Draw a diagonal in the terminal
 * @n: Number of diagonal to print
 * Return: None
 */

void print_diagonal(int n)
{
	int to_print, diag_space;

	if (n <= 0)
	{
		_putchar(10);
	}
	else
	{
		for (to_print = 1; to_print <= n; to_print++)
		{
			for (diag_space = 1; diag_space < to_print; diag_space++)
			{
				_putchar(32);
			}
		_putchar(92);
		_putchar(10);
		}
	}
}

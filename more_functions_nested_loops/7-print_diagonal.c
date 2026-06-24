#include "main.h"

/**
 * print_diagonal - Draw a diagonal in the terminal
 * @n: Number of diagonal to print
 * Return: None
 */

void print_diagonal(int n)
{
	int to_print, diag_space;

	if (n == 0)
	{
		_putchar('\n');
	}
	else
	{
		for (to_print = 0; to_print < n; to_print++)
		{
			for (diag_space = 0; diag_space < (to_print + 1); diag_space++)
			{
				_putchar(' ');
			}
		_putchar('\\');
		_putchar('\n');
		}
	}
}

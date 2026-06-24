#include "main.h"

/**
 * print_triangle - Draw a triangle in the terminal
 * @size: The size of the triangle to draw
 * Return: None
 */

void print_triangle(int size)
{
	int space, symbole, run;

	if (size <= 0)
	{
		_putchar(10);
	}
	else
	{
		for (run = 0; run < size; run++)
		{
			for (space = size; space > run; space--)
			{
				_putchar(32);
			}

			for (symbole = 0; symbole <= run; symbole++)
			{
				_putchar(35);
			}
			_putchar(10);
		}
	}
}

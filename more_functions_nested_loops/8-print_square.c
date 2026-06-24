#include "main.h"

/**
 * print_square - Draw a square in the terminal
 * @size: Number of face to print
 * Return: None
 */

void print_square(int size)
{
	int line_to_draw, symbole_to_draw;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (line_to_draw = 0; line_to_draw < size; line_to_draw++)
		{
			for (symbole_to_draw = 0; symbole_to_draw < size; symbole_to_draw++)
			{
				_putchar('#');
			}
		_putchar('\n');
		}
	}
}

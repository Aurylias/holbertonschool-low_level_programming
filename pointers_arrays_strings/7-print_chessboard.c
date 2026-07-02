#include "main.h"

/**
 * print_chessboard - Print a chess board
 * @a: 2 dimensional array
 * Return: None
 */

void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; i < 8; j++)
		{
			_putchar(a[i][j])
		}
		_putchar(10);
	}
}

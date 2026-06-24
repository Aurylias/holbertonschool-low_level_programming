#include "main.h"

/**
 * more_numbers - Print 0123456789 10 times
 * Return: None
 */

void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (i > 9)
			{
				_putchar('1');
				
			}
			_putchar('0' + (j % 10));
		}
		_putchar('\n');
	}
}

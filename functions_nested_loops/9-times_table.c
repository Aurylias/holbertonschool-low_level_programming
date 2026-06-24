#include "main.h"

/**
 * times_table - Print the 9 times table
 * Return: None
 */

void times_table(void)
{
	int table_count, table;

	for (table = 0; table <= 9; table++)
	{
		for (table_count = 0; table_count <= 9; table_count++)
		{
			int result = table * table_count;

			if (table_count == 0)
			{
				_putchar('0' + result);
			}
			else if (result <= 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar('0' + result);
			}
			else if (result > 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar('0' + (result / 10));
				_putchar('0' + (result % 10));
			}
		}
		_putchar('\n');
	}
}

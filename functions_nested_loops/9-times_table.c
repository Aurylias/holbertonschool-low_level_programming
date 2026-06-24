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
		for (table_count = 0; table_count <=9; table_count++)
		{
			int result = table * table_count;

			if (result < 10)
			{
				_putchar('0' + result);
				
				if (table_count != 9)
				{
					_putchar(',');
				}

				_putchar(' ');
			}
			else
			{
				_putchar('0' + (result / 10));
				_putchar('0' + (result % 10));
				if (result != 81)
				{
					_putchar(',');
					_putchar(' ');
				}
			}

			if (table_count == 9)
			{
				_putchar('\n');
			}
		}
	}
}
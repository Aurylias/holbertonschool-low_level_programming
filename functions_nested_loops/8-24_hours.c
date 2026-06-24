#include "main.h"

/**
 * jack_bauer - Print the hour from 00:00 to 23:59
 * Return: None
 */

void jack_bauer(void)
{
	int hours_tens_digit;
	int hours_digit;
	int minutes_tens_digit;
	int minute_digit;
	int hours_digit_turn = 0;

	for (hours_tens_digit = 0; hours_tens_digit <= 2; hours_tens_digit++)
	{
		hours_digit_turn++;
		for (hours_digit = 0; hours_digit_turn <= 2; hours_digit++)
		{
			for (minutes_tens_digit = 0; minutes_tens_digit <= 5; minutes_tens_digit++)
			{
				for (minute_digit = 0; minute_digit <= 9; minute_digit++)
				{
					_putchar(hours_tens_digit + '0');

					if (hours_digit_turn == 2)
					{
						hours_digit = 3;
					}

					_putchar(hours_digit + '0');
					_putchar(':');
					_putchar(minutes_tens_digit + '0');
					_putchar(minute_digit + '0');
					_putchar('\n');
				}
			}
		}
	}
}

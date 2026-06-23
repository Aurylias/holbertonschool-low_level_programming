#include <stdio.h>

/**
 * main - Print all possible combinations of single-digit numbers
 * Return: Always 0 (Success)
 */

int main(void)
{
	int digits;
	int tens;

	for (tens = 48; tens < 58; tens++)
	{
		for (digits = 48; digits < 58; digits++)
		{
			putchar(tens);
			putchar(digits);
			putchar(44);
			putchar(32);
		}
	}

	return (0);
}

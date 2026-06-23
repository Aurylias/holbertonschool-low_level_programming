#include <stdio.h>

/**
 * main - Print all possible combinations of single-digit numbers
 * Return: Always 0 (Success)
 */

int main(void)
{
	int number;

	for (number = 48; number < 58; number++)
	{
		putchar(number);

		if (number == 57)
		{

		}
		else
		{
			putchar(44);
			putchar(32);
		}
	}

	putchar(10);

	return (0);
}

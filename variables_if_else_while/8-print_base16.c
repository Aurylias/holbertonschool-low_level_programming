#include <stdio.h>

/**
 * main - Print the base16 symboles
 * Return: Always 0 (Success)
 */

int main(void)
{
	int number;
	char letter;

	for (number = 48; number < 58; number++)
	{
		putchar(number);
	}

	for (letter = 97; letter < 103; letter++)
	{
		putchar(letter);
	}

	putchar(10);

	return (0);
}

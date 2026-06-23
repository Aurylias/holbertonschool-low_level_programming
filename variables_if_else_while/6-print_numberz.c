#include <stdio.h>

/**
 * main - Print the alphabet
 * Return: Always 0 (Success)
 */

int main(void)
{
	int a = 0;
	int char_value = 48;

	do {
		putchar(char_value);
		a++;
		char_value++;
	} while (a < 10);
	putchar(10);

	return (0);
}

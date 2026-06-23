#include <stdio.h>

/**
 * main - Print the alphabet in reverse
 * Return: Always 0 (Success)
 */

int main(void)
{
	int char_value = 122;

	do {
		putchar(char_value);
		char_value--;
	} while (char_value > 96);
	putchar(10);

	return (0);
}

#include <stdio.h>

/**
 * main - Print the alphabet
 * Return: Always 0 (Success)
 */

int main(void)
{
	int a = 0;

	do {
		printf("%d", a++);
	} while (a < 10);
	puts("\n")

	return (0);
}

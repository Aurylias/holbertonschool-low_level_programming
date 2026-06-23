#include <stdio.h>

/**
 * main - Print the alphabet
 * Return: Always 0 (Success)
 */

int main(void)
{
	int a;

	for (a = 97; a <= 122; a++)
	{
		putchar(a);
	}
	putchar(13);
	return (0);
}

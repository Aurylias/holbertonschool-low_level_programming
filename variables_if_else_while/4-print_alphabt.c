#include <stdio.h>

/**
 * main - Print the alphabet without letter e and q
 * Return: Always 0 (Success)
 */

int main(void)
{
	int a;

	for (a = 97; a <= 122; a++)
	{
		if (a == 113 || a == 101)
		{

		}
		else
		{
			putchar(a);
		}
	}

	putchar(10);

	return (0);
}

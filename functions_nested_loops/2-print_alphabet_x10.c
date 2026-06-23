#include "main.h"

/**
 * print_alphabet_x10 - Print the alphabet ten times
 * Return: None
 */

void print_alphabet_x10(void)
{
	char letter;
	int times;

	for (times = 0; times < 10; times++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}
	}
	
	_putchar('\n');
}

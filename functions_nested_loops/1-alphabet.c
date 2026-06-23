#include <main.h>

/**
 * print_alphabet - Print the alphabet
 * Return: None
 */

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z', letter++)
	{
		_putchar(letter);
	}

	_putchar('\n')
}

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	print_alphabet();
	return (O);
}

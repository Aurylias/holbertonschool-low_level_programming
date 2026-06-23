#include <main.h>

/**
 * main - A function which print the alphabet
 * Return: Always 0 (Success)
 */

 void print_alphabet(void)
 {
	char letter;

	for(letter = 'a'; letter <= 'z', letter++)
	{
		_putchar(letter);
	}

	_putchar('\n')
 }

 int main(void)
 {
	print_alphabet();
	return (O)
 }

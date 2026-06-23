#include "main.h"

/**
 * print_last_digit - Return the last digit of an integer
 *@n: The value of an int
 * Return: An int, the last digit of n
 */

int print_last_digit(int n)
{
	char last = n % 10;

	if (last < 0)
	{
		_putchar(-last + '0');
		return (-last);
	}
	else
	{
		_putchar(last + '0');
		return (last);
	}

	
}
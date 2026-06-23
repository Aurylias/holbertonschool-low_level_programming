#include "main.h"

/**
 * print_sign - Check if a number is great, lower or equal to 0
 *@n: The value of an int
 * Return: An int, 1, 0 or -1
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}

#include "main.h"

/**
 * _abs - Return the absolute value of an integer
 *@n: The value of an int
 * Return: An int, the absolute value of n
 */

int _abs(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	else
	{
		return (n);
	}
}

#include "main.h"

/**
* factorial - Calculate the factorial of a given number
* @n: The integer to use for the calculation
* Return: The factorial
*/

int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}

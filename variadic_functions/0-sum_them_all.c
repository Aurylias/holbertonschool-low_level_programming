#include "variadic_functions.h"

/**
* sum_them_all - Get the sum of all arguments
* @n: Number of argument passed
* Return: The sum of all arguments
*/

int sum_them_all(const unsigned int n, ...)
{
	va_list numbers;
	int sum = 0;
	unsigned int i;

	va_start(numbers, n);
	for (i = 0; i < n; i++)
		sum += va_arg(numbers, int);

	va_end(numbers);

	return (sum);
}

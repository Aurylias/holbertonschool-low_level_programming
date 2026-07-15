#include "variadic_functions.h"

/**
* print_numbers - Print numbers followed by a new line
* @separator: String to be printed between numbers
* @n: Number of integers passed to the function
* Return: None
*/

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;

	va_start(numbers, n);
	for (i = 0; i < n; i++)
	{
		if (separator == NULL)
		{
			printf("%d", va_arg(numbers, int));
		}
		else
		{
			printf("%d%s", va_arg(numbers, int), separator);
		}
	}
	printf("\n");
}

#include "variadic_functions.h"

/**
* print_strings -
* @separator: String to be printed between numbers
* @n: Number of strings passed to the function
* Return: None
*/

void print_strings(const char *separator, const unsigned n, ...)
{
	va_list str;
	unsigned int i;

	va_start(str, n);
	for (i = 0; i < n; i++)
	{
		if (va_arg(str,char *) == NULL)
			printf("(nil)");
		else
		{
			printf("%s", va_arg(str, char *));
		}
		if (i < n - 1 && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
}

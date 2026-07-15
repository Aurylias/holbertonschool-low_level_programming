#include "variadic_functions.h"

void print_char(va_list *args);
void print_integer(va_list *args);
void print_float(va_list *args);
void print_string(va_list *args);

/**
* print_all - Prints all parameters passed to the function
* @format: String with types of variables, in order
* Return: None
*/

void print_all(const char * const format, ...)
{
	va_list all;
	unsigned int i = 0;
	unsigned int n = 0;
	char *seperator = "";

	conv_t convs[] = {
		{'c', print_char},
		{'i', print_integer},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};

	va_start(all, format);
	while (format && (*(format + i)))
	{
		n = 0;
		while (convs[n].type != *(format + i) && convs[n].f != NULL)
			n++;
		if (convs[n].f != NULL)
		{
			printf("%s", seperator);
			convs[n].f(&all);
			seperator = ", ";
		}
		i++;
	}

	va_end(all);
	putchar('\n');
}

/**
 * _print_char - Prints a character
 * @args: va_list to get character from, presumed to be type of arg
 * Return: None
 */

void print_char(va_list *args)
{
	char ch;

	ch = va_arg(*args, int);
	printf("%c", ch);
}

/**
 * _print_integer - Prints an integer
 * @args: va_list to get integer from, presumed to be type of arg
 * Return: None
 */
void print_integer(va_list *args)
{
	int i;

	i = va_arg(*args, int);
	printf("%d", i);
}

/**
 * _print_float - Prints a float
 * @args: va_list to get float from, presumed to be type of arg
 * Return: always void
 */
void print_float(va_list *args)
{
	float f;

	f = va_arg(*args, double);
	printf("%f", f);
}

/**
 * _print_string - Prints a string
 * @args: va_list to get char * from, presumed to be type of arg
 * Return: always void
 */
void print_string(va_list *args)
{
	char *str;

	str = va_arg(*args, char *);
	if (str == NULL || *str == '\0')
		str = "(nil)";

	printf("%s", str);
}
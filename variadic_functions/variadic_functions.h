#ifndef variadic_functions_h
#define variadic_functions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct convert
{
	char type;
	void (*f)(va_list *);
} conv_t;

int _putchar(char c);

int sum_them_all(const unsigned int n, ...);

void print_numbers(const char *separator, const unsigned int n, ...);

void print_strings(const char *separator, const unsigned n, ...);

void print_all(const char * const format, ...);

#endif

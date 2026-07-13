#include "function_pointers.h"
#include <stdlib.h>

/**
* print_name - Print a string using different fonction
* @name: String to print
* @f: A function accepting a string
* Return: None
*/

void print_name(char *name, void (*f)(char *))
{
	f(name);
}

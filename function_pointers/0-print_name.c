#include "main.h"
#include <stdlib.h>

/**
* print_name - 
* @name:
* Return: None
*/

void print_name(char *name, void (*f)(char *))
{
	f(name);
}

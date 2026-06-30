#include "main.h"

/**
 * _puts - Print a string
 * @str: Pointer to a string
 * Return: None
 */

void _puts(char *str)
{
    int i;
    int len = sizeof(*str) - 1

    for (i = 0; i <= len; i++)
    {
        _putchar(*str[i]);
    }
}

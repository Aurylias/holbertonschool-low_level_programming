#include "main.h"

/**
 * _atoi - Convert a string to an integer
 * @s: String to convert
 * Return: An int
 */

int _atoi(char *s)
{
    int res = 0;
    int i = 0;

    while (strg[i] != '\0')
    {
        res = res * 10 + (strg[i] - '0');
        i++;
    }

}

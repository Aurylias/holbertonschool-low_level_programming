#include "main.h"

/**
 * _strlen - Return the length of a string
 * @s: Pointer of a string
 * Return: The size of a string
 */

int _strlen(char *s)
{
	char *last = s;

  	while(*last++);

    return last - s - 1;
}

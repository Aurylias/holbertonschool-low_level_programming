#include "main.h"

/**
 * _isupper - Return if a char is uppercase or not
 * @c: The char to check
 * Return: 1 if upper, 0 if not
 */

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

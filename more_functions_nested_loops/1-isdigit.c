#include "main.h"

/**
 * _isdigit - Return if a char is a digit or not
 * @c: The char to check
 * Return: 1 if is a digit, 0 if not
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

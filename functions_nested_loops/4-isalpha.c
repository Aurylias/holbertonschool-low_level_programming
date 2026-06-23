#include "main.h"

/**
 * _isalpha - Check if the letter is upper or lower case
 *@c: The char value
 * Return: An int equal to 1 or 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

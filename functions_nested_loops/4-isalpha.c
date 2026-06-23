#include "main.h"

/**
 * _isalpha - Check if the letter is upper or lower case
 *@c: The char value
 * Return: None
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

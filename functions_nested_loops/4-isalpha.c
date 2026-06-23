#include "main.h"

/**
 * _islower - Print the alphabet ten times
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

#include "main.h"

/**
 * _islower - Print the alphabet ten times
 *@c: The char value
 * Return: None
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

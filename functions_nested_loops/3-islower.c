#include "main.h"

/**
 * _islower - Check if the letter is lower case
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

#include "main.h"

/**
 * _islower - Print the alphabet ten times
 *@c: The char value
 * Return: None
 */

int _islower(int c)
{
	int letter;
	int check = 0;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (c != letter)
		{
			check++;
		}
	}

	if (check > 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

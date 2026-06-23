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

	for (letter = 97; letter <= 122; letter++)
	{
		if (c != letter)
		{
			check++;
		}
	}

	for (letter = 48; letter <= 57; letter++)
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

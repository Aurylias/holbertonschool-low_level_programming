#include "main.h"

int _strlen(char *s);

/**
 * _strlen - Return the length of a string
 * @s: Pointer of a string
 * Return: The size of a string
 */

int _strlen(char *s)
{
	char *last = s;

	while (*last++)
	{

	}

	return (last - s - 1);
}

/**
 * rev_string - Reverse a given string
 * @s: Test
 * Return: None
 */

void rev_string(char *s)
{
	int i = _strlen(s) - 1;
	int j = 0;
	char str;

	for (; j < i; i--)
	{
		str = s[j];
		s[j] = s[i];
		s[i] = str;

		j++;
	}
}

#include "main.h"
#define NULL 0

/**
 * _strchr - Locates a character in a string
 * @s: String to find
 * @c: Char to find
 * Return: A pointer to a char
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0' && s[i] != c; i++)
	{

	}

	if (s[i] == c)
	{
		return (&s[i]);
	}
	else
	{
		return (NULL);
	}
}

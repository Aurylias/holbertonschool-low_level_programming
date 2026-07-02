#include "main.h"
#define NULL 0

/**
 * _strpbrk - Search a string for any set of bytes
 * @s: String to search in
 * @accept: The substring
 * Return: Number of bytes int the initial segment of s
 */

char *_strpbrk(char *s, char *accept)
{
	unsigned int i = 0;
	int j;

	while (s[i] != '\0')
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				s = &s[i];
				return (s);
			}
		}
		i++;
	}
	return (NULL);
}

#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: String to search in
 * @accept: The substring
 * Return: Number of bytes int the initial segment of s
 */

unsigned int _strspn(char *s, char *accept)
{
	int i = 0, occurence = 0;
	int j;

	while (str[i] != '\0')
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (str[i] == accept[j])
			{
				occurence++;
				break;
			}
			if (accept[j] == '\0' && s[i] != accept[j])
			{
				return (occurence);
			}
		}
	}
	return (occurence);
}

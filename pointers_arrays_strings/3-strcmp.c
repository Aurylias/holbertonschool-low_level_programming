#include "main.h"

/**
 * _strcmp - Compare if two string are equal
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: 0 if equal, 1 or -1 if the missmatch is greater than the other
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j])
		{
			return (0);
		}
		else if (s1[i] > s2[j])
		{
			return (1);
		}
		else if (s2[j] > s1[i])
		{
			return (-1);
		}
	}

	return (0);
}

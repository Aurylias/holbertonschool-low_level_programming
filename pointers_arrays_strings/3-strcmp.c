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
		if (s1[i] != s2[j])
		{
			if (s1[i] > s2[j])
			{
				return (s1[i] - s2[j]);
			}
			else
			{
				return (s2[i] - s1[j]);
			}
		}	

		i++;
		j++;
	}

	return (0);
}

#include "main.h"

/**
 * _strcmp - 
 * @s1:
 * @s2: 
 * Return: An int
 */

int _strcmp(char *s1, char *s2)
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s2[j] != '\0'; j++)
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
	}
}

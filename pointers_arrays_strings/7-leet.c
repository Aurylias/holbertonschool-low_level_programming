#include "main.h"

/**
 * leet - Encode a string in 1337
 * @str: Pointer to a string
 * Return: A pointer to a char
 */

char *leet(char *str)
{
	int i, j;
	char from[] = "aAeEoOtTlL";
	char to[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; from[i] != '\0'; j++)
		{
			if (str[i] == from[j])
			{
				str[i] = to[j];
			}
		}
	}
	return (str);
}

#include "main.h"

/**
 * leet - Encode a string in 1337
 * @str: Pointer to a string
 * Return: A pointer to a char
 */

char *leet(char *str)
{
	int i = 0;
	int j;
	char from[] = "aAeEoOtTlL";
	char to[] = "4433007711";

	while (str[i] != '\0')
	{
		for (j = 0; from[i] != '\0')
		{
			if (str[i] == from[j])
			{
				str[i] = to[j];
			}
		}
	}
	return (str);
}

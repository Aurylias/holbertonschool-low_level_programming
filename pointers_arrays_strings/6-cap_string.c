#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string
 * Return: A char pointer
 */

char *cap_string(char *str)
{
	char seprarator[] = " \t\n,;.!?\"(){}";
	int i, j, separat;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0)
		{
			str[i] = str[i] - 32;
		}
		else
		{
			for (j = 0; seprarator[j] != '\0'; j++)
			{
				if (str[i] == seprarator[j])
				{
					separat = 1;
					break;
				}
			}
		}
		if (separat)
		{
			if (str[i] >= 97 && str[i] <=  122)
			{
				str[i] = str[i] - 32;
			}
		}
	}
}

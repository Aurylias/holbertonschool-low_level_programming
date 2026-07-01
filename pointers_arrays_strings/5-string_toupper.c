#include "main.h"

/**
 * string_toupper - Change all lowercase to uppercase
 * @str: The string to change
 * Return: Pointer to a char
 */

char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = (str[i] - 32);
		}

		i++;
	}

	return (str);
}

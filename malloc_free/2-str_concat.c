#include "main.h"
#include <stdlib.h>

/**
* str_concat - Concatenates two strings
* @s1: Left side of the string
* @s2: Right side of the sting
* Return: Return a pointer to the new string
*/

char *str_concat(char *s1, char *s2)
{
	char *new_string;
	int len_s1, len_s2;
	int i;

	if (s1 == NULL && s2 == NULL)
	{
		new_string = "";
		return (new_string);
	}
	else if (s1 == NULL)
	{
		len_s1 = 0;
	}
	else if (s2 == NULL)
	{
		len_s2 = 0;
	}

	while (s1[len_s1] != '\0')
		len_s1++;

	while (s1[len_s2] != '\0')
		len_s2++;

	new_string = malloc((sizeof(*new_string) * len_s1) +
				(sizeof(*new_string * len_s2)));

	for (i = 0; s1[i] != '\0'; i++)
	{
		new_string[i] = s1[i];
	}

	for (i = 0; s2[i] != '\0'; i++)
	{
		new_string[len_s2 + i] = s2[i];
	}

	return (new_string);
}

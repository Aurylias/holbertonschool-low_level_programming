#include "main.h"
#include <stdlib.h>

/**
* string_nconcat - Concatenates two string
* @s1: Left part of the string
* @s2: Right part of the string
* @n: Number of bytes of s2 to use
* Return: Pointer to the newly allocated memory space
*/

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int len_s1, len_s2 = 0;
	unsigned int i;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	while (s1[len_s1] != '\0')
		len_s1++;

	while (s2[len_s2] != '\0')
		len_s2++;

	if (n >= len_s2)
	{
		n = len_s2;
	}

	str = malloc(sizeof(*str) * (len_s1 + n + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < len_s1; i++)
	{
		str[i] = s1[i];
	}

	for (i = 0; i < n; i++)
	{
		str[len_s1 + i] = s2[i];
	}

	str[len_s1 + n] = '\0';

	return (str);
}

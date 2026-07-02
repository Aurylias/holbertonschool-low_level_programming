#include "main.h"

/**
 * _strstr - Locates a substring
 * @haystack: 
 * @needle:
 * Return:
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j, x;

	if (needle[0] == '\0')
	{
		return (haystack);
	}

	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			x = i;
			j = 0;
			while (needle[j] != '\0')
			{
				if (haystack[x] == needle[j])
				{
					x++;
					j++;
				}
				else
				{
					break;
				}
			}
			if (needle[j] == '\0')
			{
				return (haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
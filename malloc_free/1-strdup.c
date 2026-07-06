#include "main.h"
#include <stdlib.h>

/**
* _strdup - Copy a string in new memory space
* @str: String to copy
* Return: Pointer to the new allocated memory
*/

char *_strdup(char *str)
{
	char *new_str;
	int len = 0;
	int i;

	if(str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	new_str = malloc(sizeof(*new_str) * len);

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}

	return (new_str);
}

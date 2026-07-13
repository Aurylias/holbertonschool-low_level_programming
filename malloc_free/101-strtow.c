#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* strtow - Splits a string into word
* @str: String to split
* Return: Poitneur to an array of word
*/

int num_word(char *str)
{
	int i, k, j;
	int count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 33 && str[i] <= 126)
		{
			k = 0;
			for (j = i; str[j] != 32; j++)
			{
				k++;
			}
			i += k;
			count++;
		}
	}

	return (count);
}

char **strtow(char *str)
{
	char word[30];
	char *arr;

	arr = malloc(sizeof(*arr) * num_word(*str));

	
}

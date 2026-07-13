#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* main - Entry point
* @argc: Number of arguments
* @argv: Array of arguments
* Return: Always O (Success)
*/

int main(int argc, char *argv[])
{
	int i;
	int result = 0;

	if (argv[1] == NULL)
		printf("0\n");

	for (i = 1; i < argc; i++)
	{
		if (!atoi(argv[i]))
		{
			result += atoi(argv[i]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d", result);

	return (0);
}

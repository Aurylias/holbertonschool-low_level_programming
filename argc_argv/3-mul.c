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
	int result;

	if ((argc - 1) != 2)
		return (1);

	result = atoi(argv[1]) * atoi(argv[2]);

	printf("%d", result);

	return (0);
}

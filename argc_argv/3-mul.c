#include "main.h"
#include <stdio.h>

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

	result = argv[1] * argv[2]

	printf("%d", result);

	return (0);
}

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
	if (argv != NULL)
		printf("%d", argc);

	return (0);
}
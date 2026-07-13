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
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}

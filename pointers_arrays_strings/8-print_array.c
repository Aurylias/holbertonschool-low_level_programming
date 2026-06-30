#include <stdio.h>
#include "main.h"

/**
 * print_array - Print all value of an array to n
 * @a: An array of int
 * @n: Index of the array to reach
 * Return: None
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i <= n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Print the sum of the two diagonals of a square matrix of integers
 * @a: 2D array
 * @size: Size of the array
 * Return: None
 */

void print_diagsums(int *a, int size)
{
	int i, j;
	int res_1 = 0, res_2 = 0;

	for (i = 0; i < size; i++)
	{
		res_1 += *(a + (i * size) + i);
	}
	for (j = 0; j < size; j++)
	{
		res_2 += *(a + (j * size) + (size - 1 - j));
	}

	printf("%d, %d\n", res_1, res_2);	
}

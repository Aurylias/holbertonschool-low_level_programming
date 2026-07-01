#include <stdio.h>

/**
 * reverse_array - Reverse an array of integers
 * @a: The array to reverse
 * @n: Number of element of the array
 * Return: None
 */

void reverse_array(int *a, int n)
{
	int temp;
	int start = 0, end = n - 1;

	while (start < end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++, end--;
	}
}

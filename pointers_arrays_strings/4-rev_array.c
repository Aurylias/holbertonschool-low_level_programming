#include <stdio.h>

/**
 * reverse_array - Reverse an array of integers
 * @a: The array to reverse
 * @n: Number of element of the array
 * Return: None
 */

void reverse_array(int *a, int n)
{
	int temp, start;
	int end = n - 1;

	for (start = 0; start < end; start++)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;

		end--;
	}
}

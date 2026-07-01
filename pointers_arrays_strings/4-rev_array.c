#include <stdio.h>

/**
 * _strlen - Return the length of a string
 * @s: Pointer of a string
 * Return: The size of a string
 */

int _strlen(char *s)
{
	char *last = s;

	while (*last++)
	{

	}

	return (last - s - 1);
}

/**
 * reverse_array - Reverse an array of integers
 * @a: The array to reverse
 * @n: Number of element of the array
 * Return: None
 */

void reverse_array(int *a, int n)
{
    int temp[n];
    int i, j;

    for (i = _strlen(a); i <= _strlen(a); i--)
    {
        temp[j] = a[i];
    }

    *a = temp;
}

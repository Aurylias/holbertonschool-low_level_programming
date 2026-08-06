#include "main.h"

/**
* find_root - Find square root of n
*
* @n: The number to use
* @i: Test to run on this root
*
* Return: The natural square root
*/

int find_root(int n, int i)
{
	if (i * i > n)
		return (-1);

	if (i * i == n)
		return (i);

	return (find_root(n, i + 1));
}

/**
* _sqrt_recursion - find natural square root
*
* @n: The number to use
*
* Return: The natural square root
*/

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (find_root(n, 0));
}

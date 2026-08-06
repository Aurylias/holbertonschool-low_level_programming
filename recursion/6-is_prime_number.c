#include "main.h"

/**
* find_prime - Find if number is prime
*
* @n: The number to test
* @i: The tester
*
* Return: 1 if number is prime number, otherwise 0
*/

int find_prime(int n, int i)
{
	if (i > n / i)
		return (1);
	else if (n % i == 0)
		return (0);
	else
		return (find_prime(n, i + 1));
}

/**
* is_prime_number - Find if a number is prime
*
* @n: The number to test
*
* Return: 1 if prime, otherwise 0
*/

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	else
		return (find_prime(n, 2));
}

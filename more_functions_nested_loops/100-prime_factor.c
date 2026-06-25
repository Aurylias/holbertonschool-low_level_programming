#include <stdio.h>

/**
 * print_triangle - Draw a triangle in the terminal
 * @size: The size of the triangle to draw
 * Return: None
 */

int is_prime(int num);

int is_prime(int num)
{
	int i;
	int count = 0;

	for (i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			count++;
		}
	}

	if (count > 2)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int main(void)
{
	int number = 612852475143;
	int i; 

	for (i = number; i > 0; i--)
	{
		if ((number % i) == 0)
		{
			if (is_prime(i))
			{
				printf("%d"; i);
				break;
			}
		}
	}
}

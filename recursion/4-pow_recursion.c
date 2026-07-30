#include "main.h"

/**
* _pow_recursion - Raise x to the power of y
* @x: The integer to raise
* @y: The power
* Return: x to the power of y
*/

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, y - 1));
}

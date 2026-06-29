#include "main.h"

/**
 * swap_int - Swap the value between two int
 * @a: A pointer
 * @b: A pointer
 * Return: None
 */

void swap_int(int *a, int *b)
{
	int a_bis = *a;
	int b_bis = *b;

	*a = b_bis;
	*b = a_bis;
}

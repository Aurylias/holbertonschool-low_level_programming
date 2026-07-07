#include "main.h"
#include <stdlib.h>

/**
* malloc_checked - Allocates memory of given size
* @b: Size to allocate
* Return: Pointer to allocated memory or exit(98)
*/

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}

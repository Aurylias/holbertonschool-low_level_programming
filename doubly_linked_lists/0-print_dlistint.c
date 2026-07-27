#include "lists.h"

/**
* print_dlistint - Print all the int of a list
* @h: pointer to the first node
* Return: Number of nodes
*/

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
	}

	return (count);
}

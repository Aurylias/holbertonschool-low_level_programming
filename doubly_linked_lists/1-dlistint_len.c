#include "lists.h"

/**
* dlistint_len - Return the length of the list
* @h: pointer to the first node
* Return: Number of nodes
*/

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}

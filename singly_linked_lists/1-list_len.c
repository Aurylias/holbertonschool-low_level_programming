#include "lists.h"

/**
* list_len - Return the length of the linked list
* @h: pointer to the first node
* Return: THe length of the list
*/

size_t list_len(const list_t *h)
{
	size_t length = 0;

	while (h != NULL)
	{
		length++;
		h = h->next;
	}

	return (length);
}

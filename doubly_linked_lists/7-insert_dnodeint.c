#include "lists.h"

/**
* insert_dnodeint_at_index - Insert a new node at the specified index
* @h: Pointeur to the head of the list
* @idx: The index to insert to
* @n: The value of n of the new node
* Return: The address of the new node or null if failed
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp = *h;
	unsigned int len = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (tmp != NULL && len < idx - 1)
	{
		tmp = tmp->next;
		len++;
	}

	if (tmp == NULL)
		return (NULL);

	if (tmp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = tmp->next;
	new->prev = tmp;
	tmp->next->prev = new;
	tmp->next = new;

	return (new);
}

#include "lists.h"

/**
* get_dnodeint_at_index - Return the nth node of the list
* @head: Pointer to the first node
* @index: The index to reach
* Return: The found node
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (i < index)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
		i++;
	}

	return (head);
}

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

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (h != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (idx == len - 1)
		return (add_dnodeint_end(h, n));

	tmp = get_dnodeint_at_index(*h, idx);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = tmp->next;
	new->prev = tmp->prev;
	tmp->next->prev = new;
	tmp->next = new;

	return (new);
}

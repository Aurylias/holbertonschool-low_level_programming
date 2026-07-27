#include "lists.h"

/**
* add_dnodeint - Add a node at the start of the list
* @h: pointer to the first node
* Return: Pointer to the new head
*/

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	*head = new;
	return (new);
}

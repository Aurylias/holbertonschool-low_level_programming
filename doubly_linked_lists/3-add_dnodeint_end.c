#include "lists.h"

/**
* add_dnodeint_end - Add a node at the end of the list
* @head: pointer to the first node
* @n: The value of n
* Return: Pointer to the new head
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *t_node;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	t_node = *head;
	while (t_node->next != NULL)
		t_node = t_node->next;
	t_node->prev = *head;
	t_node->next = new;

	return (new);
}

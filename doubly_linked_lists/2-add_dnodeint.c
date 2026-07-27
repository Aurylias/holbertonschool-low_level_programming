#include "lists.h"

/**
* add_dnodeint - Add a node at the start of the list
* @head: pointer to the first node
* @n: The value of n
* Return: Pointer to the new head
*/

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);



	new->n = n;

	if (*head != NULL)
		(*head)->prev = new;

	new->next = *head;
	*head = new;
	return (new);
}

#include "lists.h"

/**
* delete_dnodeint_at_index - Delete a node from a specified index
* @head: Pointer to the head of the list
* @index: Index of the node to delete
* Return: 1 if succeeded, -1 if not
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;
	unsigned int len = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	while (tmp != NULL && len < index)
	{
		tmp = tmp->next;
		len++;
	}

	if (tmp == NULL)
		return (-1);

	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	else
		*head = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}

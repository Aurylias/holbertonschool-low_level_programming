#include "lists.h"

/*
* get_dnodeint_at_index - Return the nth node of the list
* @head: Pointer to the first node
* @index: The index to reach
* Return: The found node
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	while(i != index)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
		i++;
	}

	return (head);
}

#include "lists.h"

/**
* free_dlistint - Free all element of the list
* @head: pointer to the first node
* Return: None
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

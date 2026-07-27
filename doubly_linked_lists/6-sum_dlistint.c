#include "lists.h"

/**
* sum_dlistint - Get the sum of all data
* @head: Pointer to the head
* Return: The sum of all data
*/

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head->next != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	
	sum += head->n;

	return (sum);
}

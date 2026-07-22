#include "lists.h"

/**
* free_list - Free all memory adress of the list
* @head: The head of the list
* Return: None
*/

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}

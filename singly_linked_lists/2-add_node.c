#include "lists.h"

/**
* add_node - add a node at the beginning of the list
* @head: The head of the list
* @str:
* Return: A pointeur to the new head or null if failed
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
	{}
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = i;
	new->next = *head;
	*head = new;
	return (new);
}

#include "lists.h"

/**
* add_node_end - Add a node at the end of the list
* @head: The head of the list
* @str: String to copy
* Return: The adress of the new node
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *t_node;
	int i;

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
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		t_node = *head;
		while (t_node->next != NULL)
		{
			t_node = t_node->next;
		}
		t_node->next = new;
	}

	return (new);
}

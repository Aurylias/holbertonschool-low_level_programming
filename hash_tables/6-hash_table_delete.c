#include "hash_tables.h"

/**
* hash_table_delete - Delete a whole hash table
* @ht: The hash table to erease
* Return: None
*/

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp = NULL, *next = NULL;
	unsigned int i = 0;

	if (ht == NULL)
		return;

	while (i < ht->size)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = next;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}

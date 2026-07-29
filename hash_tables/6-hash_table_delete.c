#include "hash_tables.h"

/**
* hash_table_delete - Delete a whole hash table
* @ht: The hash table to erease
* Return: None
*/

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp = NULL;
	hash_node_t *tmp_tmp = NULL;
	unsigned int i = 0;

	if (ht == NULL)
		return;

	while (i < ht->size)
	{
		tmp = ht->array[i];
		if (tmp)
		{
			while (tmp)
			{
				tmp_tmp = tmp->next;
				free(tmp->key);
				free(tmp->value);
				free(tmp);
				tmp = tmp_tmp;
			}
		}
		i++;
	}
	free(ht->array);
	free(ht);
}

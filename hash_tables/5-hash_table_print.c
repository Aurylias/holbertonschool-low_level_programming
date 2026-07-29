#include "hash_tables.h"

/**
* hash_table_print - Print all element in hash table
* @ht: The hash table to print
* Return: None
*/

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp = NULL;
	unsigned int i = 0;
	unsigned int bool;

	printf("{");
	while (i < ht->size)
	{
		tmp = ht->array[i];
		bool = 0;
		if (tmp)
		{
			if (bool)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			bool = 1;
			tmp = tmp->next;
			while (tmp)
			{
				printf("'%s': '%s'", tmp->key, tmp->value);
				tmp = tmp->next;
			}
		}
		i++;
	}
	printf("}");
}

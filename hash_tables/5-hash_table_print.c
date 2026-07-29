#include "hash_tables.h"

/**
* hash_table_print - Print all element in hash table
* @ht: The hash table to print
* Return: None
*/

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *a_tmp = NULL;
	unsigned int i = 0;

	printf("{");
	while (i < ht->size)
	{
		a_tmp = ht->array[i];
		printf("'%s': '%s', ", a_tmp->key, a_tmp->value);
		a_tmp = a_tmp->next;
		while (a_tmp)
		{
			printf("'%s': '%s', ", a_tmp->key, a_tmp->value);
			a_tmp = a_tmp->next;
		}

		i++;
	}
	printf("}");
}

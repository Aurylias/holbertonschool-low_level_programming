#include "hash_tables.h"

/**
* hash_table_print - Print all element in hash table
* @ht: The hash table to print
* Return: None
*/

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *a_tmp = NULL, *l_tmp = NULL;
	unsigned int i = 0;

	while (a_tmp)
	{
		a_tmp = ht->array[i];
		printf("{'%s': '%s', }", a_tmp->key, a_tmp->value);

		if (!a_tmp->next)
		{
			l_tmp = a_tmp->next;
			while (l_tmp)
			{
				printf("{'%s': '%s', }", l_tmp->key, l_tmp->value);
				l_tmp = l_tmp->next;
			}
		}
		i++;
	}
}

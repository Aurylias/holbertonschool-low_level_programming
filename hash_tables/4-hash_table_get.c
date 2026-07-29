#include "hash_tables.h"

/**
* hash_table_get - Retrieves a value with a key
* @ht: The hash table we want to look into
* @key: The key we'll be using
* Return: The value associated with the key
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *tmp = NULL;
	unsigned long int index;

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			return (tmp->value);
		}
		tmp = tmp->next;
	}

	return (NULL);
}

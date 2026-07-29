#include "hash_tables.h"

/**
* hash_table_set - Adds element to the hash table
* @ht: The hash table we want to add to
* @key: The key
* @value: The value of the key
* Return: 1 if it succeeded, 0 otherwise
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node = NULL, *tmp = NULL;
	unsigned long int index;

	if (!key || !ht || !(ht->array))
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	if(!tmp)
	{
		node = (hash_node_t *)malloc(sizeof(hash_node_t));
		if (!node)
			return (0);
		node->key = strdup(key);
		node->value = strdup(value);
		node->next = NULL;
		ht->array[index] = node;
	}
	else
	{
		while(tmp)
		{
			if (strcmp(tmp->key, key) == 0)
			{
				free(tmp->value);
				tmp->value = strdup(value);
				return (0);
			}
		tmp = tmp->next;
		}
		node = (hash_node_t *)malloc(sizeof(hash_node_t));
		if (!node)
			return (0);
		node->key = strdup(key);
		node->value = strdup(value);
		node->next = ht->array[index];
		ht->array[index] = node;
	}

	return (1);
}

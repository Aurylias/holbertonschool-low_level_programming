#include "hash_tables.h"

/**
* hash_table_set - Adds element to the hash table
* @ht: The hash table we want to add to
* @key: The key
* @value: The value of the key
* Return: 1 if it succeeded, 0 otherwise
* Description : Made with the AI as a teacher, no answer given by it
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node = NULL, *tmp = NULL;
	unsigned long int index;

	if (!key || !ht || !(ht->array) || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}
	node = (hash_node_t *)malloc(sizeof(hash_node_t));
	if (!node)
		return (0);
	node->key = strdup(key);
	if (!node->key)
	{
		free(node->key);
		free(node);
		return (0);
	}
	node->value = strdup(value);
	if (!node->value)
	{
		free(node->value);
		free(node->key);
		free(node);
		return (0);
	}
	node->next = ht->array[index];
	ht->array[index] = node;
	return (1);
}

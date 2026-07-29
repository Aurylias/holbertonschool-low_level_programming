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
	tpm = ht->array[index];
}

#include "hash_tables.h"

/**
* key_index - Give the index of the key
* @key: The key
* @size: The size of the array
* Return: The index of the key
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int h_key;

	h_key = hash_djb2(key);

	return (h_key % size);
}

#include "hash_tables.h"

/**
 * hash_table_delete - function that deletes a hash table
 * @ht: pointer to hash table
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *bucket, *node_to_free;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		bucket = ht->array[i];
		while (bucket)
		{
			node_to_free = bucket;
			bucket = bucket->next;
			if (node_to_free->key)
				free(node_to_free->key);
			if (node_to_free->value)
				free(node_to_free->value);
			free(node_to_free);
		}
	}
	free(ht->array);
	free(ht);
}

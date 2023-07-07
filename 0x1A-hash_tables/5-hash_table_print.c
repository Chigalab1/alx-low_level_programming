#include "hash_tables.h"

/**
 * hash_table_print -  function that prints a hash table
 * @ht: pointer to hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t  *bucket;
	int first_printed = 0;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		bucket = ht->array[i];
		while (bucket)
		{
			if (first_printed)
				printf(", ");
			printf("'%s': '%s'", bucket->key, bucket->value);
			first_printed = 1;
			bucket = bucket->next;
		}
	}
	printf("}\n");
}

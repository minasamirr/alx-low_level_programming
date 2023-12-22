#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *current = ht->array[i];

		while (current != NULL)
		{
			printf("'%s': '%s'", current->key, current->value);

			current = current->next;
			if (current != NULL)
				printf(", ");
		}
	}

	printf("}\n");
}

#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node;
	    shash_node_t *current, *prev;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }
    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->next = NULL;
    new_node->sprev = NULL;
    new_node->snext = NULL;

    index = key_index((const unsigned char *)key, ht->size);


    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        current = ht->shead;
        prev = NULL;

        while (current != NULL && strcmp(key, current->key) > 0)
        {
            prev = current;
            current = current->snext;
        }

        if (prev == NULL)
        {
            new_node->snext = ht->shead;
            if (ht->shead != NULL)
                ht->shead->sprev = new_node;
            ht->shead = new_node;
        }
        else
        {
            new_node->snext = prev->snext;
            if (prev->snext != NULL)
                prev->snext->sprev = new_node;

            prev->snext = new_node;
            new_node->sprev = prev;

            if (new_node->snext == NULL)
                ht->stail = new_node;
        }
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    *current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);

        current = current->next;
    }

    return (NULL);
}

void shash_table_print(const shash_table_t *ht)
{
    if (ht == NULL)
        return;

    printf("{");

    shash_node_t *current = ht->shead;

    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);

        current = current->snext;
        if (current != NULL)
            printf(", ");
    }

    printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
    if (ht == NULL)
        return;

    printf("{");

    shash_node_t *current = ht->stail;

    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);

        current = current->sprev;
        if (current != NULL)
            printf(", ");
    }

    printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
    if (ht == NULL)
        return;

    shash_node_t *current = ht->shead;
    shash_node_t *next;

    while (current != NULL)
    {
        next = current->snext;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }

    free(ht->array);
    free(ht);
}


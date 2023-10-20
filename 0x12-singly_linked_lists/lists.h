#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct list_s - A structure to represent a linked list node.
 * @str: Pointer to a string stored in the node.
 * @len: Length of the string.
 * @next: Pointer to the next node in the linked list.
 *
 * Description:
 * This structure defines a node for a singly linked list. It contains a
 * string pointer (@str) to store the string data, an unsigned integer (@len)
 * to store the length of the string, and a pointer to the next node (@next).
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h);

size_t list_len(const list_t *h);

list_t *add_node(list_t **head, const char *str);

void free_list(list_t *head);

#endif

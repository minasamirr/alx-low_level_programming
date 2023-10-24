#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: A pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	size_t count = 0;

	current = head;
	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);

		if (count >= 1024)
		{
			fprintf(stderr, "Error: Exceeded maximum node count.\n");
			exit(98);
		}

		current = current->next;
		count++;
	}

	return (count);
}

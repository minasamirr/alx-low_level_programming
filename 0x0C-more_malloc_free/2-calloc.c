#include "main.h"

/**
 * _calloc - Allocates memory for an array of nmemb elements of size bytes each
 *           and initializes the memory to zero.
 * @nmemb: The number of elements in the array.
 * @size: The size of each element in bytes.
 *
 * Return: A pointer to the allocated memory, or NULL if allocation fails or
 *         if nmemb or size is 0.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;
	ptr = malloc(total_size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total_size; i++)
		*((char *)ptr + i) = 0;

	return (ptr);
}

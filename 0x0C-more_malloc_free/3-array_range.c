#include "main.h"

/**
 * array_range - Creates an array of integers from min to max (inclusive).
 * @min: The minimum value.
 * @max: The maximum value.
 *
 * Return: A pointer to the newly created array, or NULL if min > max or if
 *         malloc fails.
 */
int *array_range(int min, int max)
{
	int *arr;
	int size, i;

	if (min > max)
		return (NULL);

	size = max - min + 1;  /* Calculate the size of the array */

	arr = malloc(size * sizeof(int));  /* Allocate memory for the array */

	if (arr == NULL)
		return (NULL);  /* Return NULL if malloc fails */

	/* Populate the array with values from min to max */
	for (i = 0; i < size; i++)
	{
		arr[i] = min + i;
	}

	return (arr);
}

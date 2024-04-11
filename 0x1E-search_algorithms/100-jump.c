#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers using Jump
 * search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where the value is located, or -1 if not found or
 * if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;
	size_t current = 0;
	size_t i;

	if (array == NULL)
		return (-1);

	while (current < size && array[current] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", current, array[current]);
		prev = current;
		current += step;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, current);

	for (i = prev; i <= current && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}

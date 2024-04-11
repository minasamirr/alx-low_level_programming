#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Search for a value in a sorted array using Jump search
 * algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in @array
 * @value: Value to search for
 *
 * Return: The index of the first occurrence of @value in @array,
 *         or -1 if @value is not present in @array or if @array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL || size == 0)
		return (-1);

	int jump = sqrt(size);
	int step = jump;

	int prev = 0;

	while (array[step - 1] < value && step < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		prev = step;
		step += jump;
		if (step >= (int)size)
			break;
	}

	printf("Value found between indexes [%d] and [%d]\n", prev, step);

	for (i = prev; i < (int)size && i < step; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}

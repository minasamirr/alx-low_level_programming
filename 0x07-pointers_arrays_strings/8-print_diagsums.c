#include "main.h"

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: Pointer to the square matrix (2D array).
 * @size: The size of the square matrix.
 */
void print_diagsums(int *a, int size)
{
	int i, j, position, left_diagonal = 0, right_diagonal = 0;

	for (i = 0; i < size; i++)
	{
		position = (i * size) + i;
		left_diagonal += *(a + position);
	}
	for (j = 0; j < size; j++)
	{
		position = (j * size) + (size - 1 - j);
		right_diagonal += *(a + position);
	}
	printf("%i, %i\n", left_diagonal, right_diagonal);
}

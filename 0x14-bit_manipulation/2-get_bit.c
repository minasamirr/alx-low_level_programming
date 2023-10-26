#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The unsigned long int number to extract the bit from.
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the specified index (0 or 1)
 * or -1 if an error occurs.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	return ((n >> index) & 1);
}

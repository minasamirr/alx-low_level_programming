#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: A pointer to the unsigned long int number to modify.
 * @index: The index of the bit to set to 1, starting from 0.
 *
 * 1UL is a constant literal that represents the integer value 1 as
 * an unsigned long integer. The UL suffix indicates that the literal
 * is of type unsigned long. This is used to ensure that the constant 1
 * is treated as an unsigned long value in the context of the bitwise
 * left-shift operation.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n |= (1UL << index);

	return (1);
}

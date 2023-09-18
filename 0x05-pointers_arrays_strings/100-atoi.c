#include "main.h"

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * we multiple the num by 10 to shift it to the left
 * then we subtract '0' ASCII code from the char to convert it to number
 * Return: integer
 */

int _atoi(char *s)
{
	int i = 1;
	unsigned int num = 0;

	do {
	if (*s == '-')
		i *= -1;

	else if (*s >= '0' && *s <= '9')
		num = num * 10 + (*s - '0');
	else if (num > 0)
		break;
	} while (*s++);

	return (num * i);
}

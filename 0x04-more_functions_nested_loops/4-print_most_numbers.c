#include "main.h"

/**
 * print_most_numbers - print 0 - 9 apart
 *                 from 2 and 4 and you can
 *                 only use _putchar twice
 * Return: Always 0 (Success)
*/

void print_most_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (!(i == 2 || i == 4))
		_putchar(i + 48);
	}
	_putchar('\n');
}

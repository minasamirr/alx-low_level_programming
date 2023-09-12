#include"main.h"

/**
 * print_alphabet_x10 - function that prints the alphabet 10 times
 *
*/

void print_alphabet_x10(void)
{
	int repeat, chr;

	for (repeat = 0; repeat < 10; repeat++)
	{
		for (chr = 'a'; chr <= 'z'; chr++)
			_putchar(chr);
		_putchar('\n');
	}
}

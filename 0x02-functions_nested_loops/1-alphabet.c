#include"main.h"

/**
 * print_alphabet - using the _putchar function to print
 *                 the alphabet a - z
*/

void print_alphabet(void)
{
	char chr;

	for (chr = 'a'; chr <= 'z'; chr++)
	{
		_putchar(chr);
	}
	_putchar('\n');
}

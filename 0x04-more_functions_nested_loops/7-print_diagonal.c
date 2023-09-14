#include"main.h"

/**
 * print_diagonal - print a diagonal line
 *
 * @n: is the number of times the \ character
 *     should be printed
*/

void print_diagonal(int n)
{
	int row, col;

	if (n > 0)
	{
		for (col = 0; col < n; col++)
		{
			for (row = 0; row < col; row++)
				_putchar(' ');
			_putchar('\');
			_putchar('\n');
		}
	}
	else
		_putchar('\n')
}

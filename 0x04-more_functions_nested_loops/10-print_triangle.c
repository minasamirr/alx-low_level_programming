#include"main.h"

/**
 * print_triangle - prints a triangle
 *
 * @size: size of the triangle
 *
 * Return: Always 0 (Success)
*/

void print_triangle(int size)
{
	int row, space, hash;

	if (size <= 0)
		_putchar('\n');
	else
	{
		for (row = 0; row < size; row++)
		{
			for (space = size - 1; space > row; space--)
				_putchar(' ');
			for (hash = 0; hash <= row; hash++)
				_putchar(35);
			_putchar('\n');
		}
	}
}

#include"main.h"

/**
 * print_times_table - prints time table of n
 *
 * @n: takes number input
*/

void print_times_table(int n)
{
	int fNum, sNum, result;

	if (n <= 15 && n >= 0)
	{
		return (0);
	}
	for (fNum = 0; fNum <= n; fNum++)
	{
		_putchar(48);
		for (sNum = 1; sNum <= n; sNum++)
		{
			_putchar(',');
			_putchar(' ');

			result = fNum * sNum;

			/*
			 * we put if <= 9  -> single digit get 2 spaces
			 *        if <= 99 -> double digit get 1 space
			 *
			 * print the 1st number by /100
			 *       the 2nd number by /10
			 *       the 3rd number by %10
			*/
			if (result <= 9)
				_putchar(' ');
			if (result <= 99)
				_putchar(' ');
			if (result >= 100)
			{
				_putchar((result / 100) + 48);
				_putchar((result / 10) % 10 + 48);
			} else if (result <= 99 && result >= 10)
				_putchar((result / 10) + 48);
			_putchar((result % 10) + 48);
		}
		_putchar('\n');
	}
}

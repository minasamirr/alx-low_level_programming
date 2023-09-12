#include"main.h"

/**
 * times_table - prints the 9 times table
 *
*/

void times_table(void)
{
	int firstNum, secNum, result;

	for (firstNum = 0; firstNum < 10; firstNum++)
	{
		_putchar(48);
		for (secNum = 1; secNum < 10; secNum++)
		{
			/*
			 * put ", " between the results
			*/
			_putchar(',');
			_putchar(' ');

			result = firstNum * secNum;

			/*
			 * put space if result is a single number
			 * place the first digit if its two numbers
			*/
			if (result < 10)
				_putchar(' ');
			else
				_putchar((prod / 10) + 48); /*get the first digit in the result*/

			_putchar((prod % 10) + 48); /*get the second digit in the result*/
		}
		_putchar('\n');
	}
}

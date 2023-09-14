#include"main.h"

/**
 * more_numbers - print 0 - 14 ten times and you
 *		can only use _putchar three times
 *
 * Return: Always 0 (Success)
*/

void more_numbers(void)
{
	int i, j = 0, num;
	
	while (j < 10)
	{
		for (i = 0; i < 15; i++)
		{
			num = i;
			if (i > 9)
			{
				_putchar(1 + 48);
				num = i % 10;
			}
			_putchar(num + 48);
		}
		_putchar('\n');
		j++;
	}
}

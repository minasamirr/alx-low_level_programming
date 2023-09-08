#include<stdio.h>

/**
 * main - Entry point
 *
 * Description: print all possible different
 *            combinations of two digits.
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int digit1 = 0;
	int digit2, digit3;

	for (digit1 = 0; digit1 < 10; digit1++)
	{
		for (digit2 = digit1 + 1; digit2 < 10; digit2++)
		{
			for (digit3 = digit2 + 1; digit3 < 10; digit3++)
			{
				putchar(digit1 + 48);
				putchar(digit2 + 48);
				putchar(digit3 + 48);

				if (digit1 + digit2 + digit3 != 24)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	return (0);
}

#include<stdio.h>

/**
 * main - Entry Point
 * Description: Write a program that prints all possible
 * different combinations of two digits
 * Return: 0
 */

int main(void)
{
	int digit1 = 0, digit2;
	for (digit1 = 0; digit1 < 100; digit1++)
	{
		for (digit2 = digit1 + 1; digit2 < 100; digit2++)
		{
			putchar((digit1 / 10) + 48);
			putchar((digit1 % 10) + 48);
			putchar(' ');
			putchar((digit2 / 10) + 48);
			putchar((digit2 % 10) + 48);
			if ((digit1 != 98) || (digit2 != 99))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}

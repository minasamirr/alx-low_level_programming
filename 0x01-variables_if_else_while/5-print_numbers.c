#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: print all single digits
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int digit = 0;

	while (digit < 10)
	{
		printf("%i", digit++);
	}
	printf("\n");

	return (0);
}

#include <stdio.h>
#include "main.h"
/**
 * main - prints the largest prime factor of 612852475143
 * 
 * Return: always 0
 **/

int largest_prime_factor(unsigned long int n)
{
	long int i, large;

	while (n % 2 == 0)
		n /= 2;
	for (i = 3; i <= n; i += 2)
	{
		while (n % i == 0)
		{
			n /= i;
			large = i;
		}
	}
	printf("%d\n", large);
}

int main(void)
{
	unsigned long int num = 612852475143;

	largest_prime_factor(num);

	return (0);
}

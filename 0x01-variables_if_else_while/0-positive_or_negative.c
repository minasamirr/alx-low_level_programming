#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: print value of n status; negative, zero, positive
 *
 * Return: Always 0 (Success)
 *
*/

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	
	/* my code goes here */
	if (n < 0)
		printf("%i is negative\n", n);
	else if (n == 0)
		printf("%i is zero\n", n);
	else
		printf("%i is positive\n", n);

	return (0);
}

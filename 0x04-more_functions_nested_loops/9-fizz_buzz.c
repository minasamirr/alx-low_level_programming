#include"main.h"

/**
 * main - print numbers 1 - 100 followed by a new line
 *       numbers that are multiples of 3 print Fizz
 *       numbers that are multiples of 5 print Buzz
 *       numbers that are multiples of 3 n 5 print FizzBuzz
 *       each number and word to be separated by space
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int count;

	for (count = 1; count < 101; count++)
	{
		if ((count % 3 == 0) && (count % 5 == 0))
			printf("FizzBuzz ");
		else if (count %  3 == 0)
			printf("Fizz ");
		else if (count % 5 == 0)
			printf("Buzz ");
		else
			printf("%d ", count);
	}
	printf("\n");

	return (0);
}

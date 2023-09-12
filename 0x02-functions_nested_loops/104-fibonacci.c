#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers, starting with
 *        1 and 2, separated by a comma followed by a space.
 *
 * Return: Always 0.
 *
 *
 * calculate fibonacci number till 91
 * to avoid overflow since we use insigned long
 *
 * break fib1 and fib2 numbers into 2 parts
 * fib*_part1 contain the 1st part of the number
 * fib*_part2 contain the 2nd part of the number
 *
 * we add the parts of the numbers
 * if the 2nd exceed 9,999,999,999
 * then there will be an overflow
 * so we add 1 to the 1st part
 * and we modules the 2nd part
 */
int main(void)
{
	int count;
	unsigned long fib1 = 0, fib2 = 1, sum;
	unsigned long fib1_part1, fib1_part2, fib2_part1, fib2_part2;
	unsigned long part1, part2;

	for (count = 0; count < 92; count++)
	{
		sum = fib1 + fib2;
		printf("%lu, ", sum);

		fib1 = fib2;
		fib2 = sum;
	}

	fib1_part1 = fib1 / 10000000000;
	fib1_part2 = fib1 % 10000000000;
	fib2_part1 = fib2 / 10000000000;
	fib2_part2 = fib2 % 10000000000;

	for (count = 93; count < 99; count++)
	{
		part1 = fib1_part1 + fib2_part1;
		part2 = fib1_part2 + fib2_part2;
		if (fib1_part2 + fib2_part2 > 9999999999)
		{
			part1 += 1;
			part2 %= 10000000000;
		}

		printf("%lu%lu", part1, part2);
		if (count != 98)
			printf(", ");

		fib1_part1 = fib2_part1;
		fib1_part2 = fib2_part2;
		fib2_part1 = part1;
		fib2_part2 = part2;
	}
	printf("\n");
	return (0);
}

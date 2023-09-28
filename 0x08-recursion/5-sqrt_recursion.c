#include "main.h"

/**
 * sqrt_helper - Helper function to find the square root using recursion.
 * @n: The number for which to calculate the square root.
 * @guess: The current guess for the square root.
 * Return: The square root of n, or -1 if it doesn't have a natural square root
 */
int sqrt_helper(int guess, int n)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (sqrt_helper(guess + 1, n));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer to find sqrt of
 * Return: natural square root or -1
 */
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (sqrt_helper(1, n));
}

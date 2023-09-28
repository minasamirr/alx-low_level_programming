#include "main.h"

/**
 * sqrt_helper - Helper function to find the square root using recursion.
 * @n: The number for which to calculate the square root.
 * @guess: The current guess for the square root.
 * Return: The square root of n, or -1 if it doesn't have a natural square root
*/
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (sqrt_helper(n, guess));
}

/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number for which to calculate the square root.
 * Return: The natural square root of n, or -1
 * if n does not have a natural square root.
*/
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (sqrt_helper(n, 1));
}

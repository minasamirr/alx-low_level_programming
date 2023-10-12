#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters.
 * @n: number of parameters
 *
 * Return: sum of all parameters, 0 if n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum;
	va_list args;
	unsigned int i;

	if (n == 0)
		return (0);

	sum = 0;
	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		int num = va_arg(args, int);

		sum += num;
	}

	va_end(args);

	return (sum);
}

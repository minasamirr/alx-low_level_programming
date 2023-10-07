#include "main.h"

/**
 * is_positive_integer - Checks if a string represents a positive integer
 * @str: The string to check
 *
 * Return: 1 if it's a positive integer, 0 otherwise
 */
int is_positive_integer(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * perform_multiplication - Performs multiplication of two positive integers
 * represented as strings
 * @num1: The first number as a string
 * @num2: The second number as a string
 * @result: The result array to store the product
 *
 * Return: Length of the result
 */
int perform_multiplication(char *num1, char *num2, int *result)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len = len1 + len2;

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			int product = (num1[i] - '0') * (num2[j] - '0');
			int sum = product + result[i + j + 1];

			result[i + j] += sum / 10;
			result[i + j + 1] = sum % 10;
		}
	}

	int i = 0;

	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		return (1);

	return (len - i);
}

/**
 * multiply - Multiplies two positive integers represented as strings
 * @num1: The first number as a string
 * @num2: The second number as a string
 *
 * Return: The result of the multiplication as a string
 */
char *multiply(char *num1, char *num2)
{
	int *result;
	int result_len;

	if (!num1 || !num2)
		return (NULL);

	result = calloc(strlen(num1) + strlen(num2), sizeof(int));

	if (!result)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	result_len = perform_multiplication(num1, num2, result);

	char *result_str = malloc(result_len + 1);

	if (!result_str)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	for (int i = 0; i < result_len; i++)
		result_str[i] = result[i] + '0';

	result_str[result_len] = '\0';
	free(result);

	return (result_str);
}

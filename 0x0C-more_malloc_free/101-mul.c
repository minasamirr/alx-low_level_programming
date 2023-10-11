#include "main.h"

/**
 * is_digit - Check if a string is composed of digits.
 * @str: The string to check.
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int is_digit(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return 0;
		str++;
	}
	return 1;
}

/**
 * multiply - Multiply two positive numbers as strings.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 * Return: The result as a dynamically allocated string.
 */
char *multiply(const char *num1, const char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len_result = len1 + len2;
	int i, j, start;
	char *result_str;
	int *result = calloc(len_result, sizeof(int));
	if (!result)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int digit1 = num1[i] - '0';
			int digit2 = num2[j] - '0';
			int product = digit1 * digit2;
			int carry = product / 10;
			int remainder = product % 10;
			result[i + j + 1] += remainder;
			result[i + j] += carry;
		}
	}

	for (i = 0; i < len_result; i++)
	{
		result[i + 1] += result[i] / 10;
		result[i] %= 10;
	}

	start = 0;
	while (start < len_result && result[start] == 0)
		start++;

	result_str = malloc(len_result - start + 1);
	if (!result_str)
	{
		free(result);
		printf("Error\n");
		exit(98);
	}

	for (i = start; i < len_result; i++)
		result_str[i - start] = result[i] + '0';
	result_str[len_result - start] = '\0';

	free(result);
	return result_str;
}

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	char *result, *num1, *num2;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		return 98;
	}

	num1 = argv[1];
	num2 = argv[2];
	result = multiply(num1, num2);

	printf("%s\n", result);
	free(result);

	return 0;
}


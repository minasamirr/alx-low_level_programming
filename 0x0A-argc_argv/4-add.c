#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * isPositiveInteger - Check if a string contains only digits
 * @str: The string to check
 *
 * Return: true if the string contains only digits, false otherwise
 */
bool isPositiveInteger(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (false);
		}
		str++;
	}
	return (true);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 for success, 1 for error
 */
int main(int argc, char *argv[])
{
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		if (isPositiveInteger(argv[i]))
		{
			int num = atoi(argv[i]);

			if (sum > INT_MAX - num)
			{
				printf("Error\n");
				return (1);
			}
			sum += num;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", sum);
	return (0);
}

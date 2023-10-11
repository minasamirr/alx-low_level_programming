#include "3-calc.h"

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments as strings
 * Return: 0 on success,
 * 98 for wrong number of arguments,
 * 99 for invalid operator,
 * 100 for division by zero
 */
int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[3]);
	char *operator = argv[2];

	int (*operation)(int, int);

	operation = get_op_func(operator);

	if (operation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", operation(num1, num2));
	return (0);
}

#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char *ptr;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	ptr = argv[2];

	if (get_op_func(ptr) == NULL || ptr[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((*ptr == 47 || *ptr == 37) && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", get_op_func(ptr)(atoi(argv[1]), atoi(argv[3])));

	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_opcodes - Print opcodes of the main function.
 * @num_bytes: Number of bytes to print.
 */
void print_opcodes(int num_bytes)
{
	char *ptr = (char *)main;

	for (int i = 0; i < num_bytes; i++)
	{
		printf("%02x", ptr[i] & 0xFF);
		if (i != num_bytes - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * main - Entry point.
 *
 * Usage: ./main number_of_bytes
 *
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	int num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	print_opcodes(num_bytes);

	return (0);
}

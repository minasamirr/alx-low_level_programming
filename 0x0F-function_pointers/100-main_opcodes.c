#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point
 *
 * Description: A program that prints the opcodes.
 * Usage: ./main number_of_bytes
 *
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0
*/

int main(int argc, char *argv[])
{
	int i;
	int count;
	char *ptr = (char *) main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	count = atoi(argv[1]);
	if (count < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < count; i++)
	{
		printf("%02x", ptr[i] & 0xFF);
		if (i != count--)
			printf(" ");
	}
	printf("\n");
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - entry point generates a random password
 *
 * Return: the generated password
*/
int main(void)
{
	char ch;
	int pass;

    srand(time(0));
	while (pass <= 2645)
	{
		ch = rand() % 128;
		pass += ch;
		putchar(ch);
	}
	putchar(2772 - pass);

	return (0);
}

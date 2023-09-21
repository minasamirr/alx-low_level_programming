#include "main.h"

/**
  * print_number - Print any integer with putchar
  * @n: Number to print
  *
  * Return: Nothing
  */
void print_number(int n)
{

	if (n < 0)
	{
		putchar('-');
		n *= -1;
	}


	if (n / 10)
		print_number(n / 10);

	putchar(n % 10 + '0');
}

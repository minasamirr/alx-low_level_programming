#include"main.h"

/**
 * main - Entry point
 *
 * Description: prints _putchar using putchar prototype
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	char outp[] = "_putchar";
	int i;

	for(i = 0; i < 8; i++)
		_putchar(outp[i]);
	_putchar("\n");

	return (0);
}

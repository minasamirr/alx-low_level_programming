#include "main.h"

/**
 * puts_half - prints half of a string
 *
 * @str: char to check
 *
 * Return: 0
 */ 
void puts_half(char *str)
{
	int length = 0, n;

	while (str[length] != '\0')
		length++;
	if (length + 1 % 2 != '0')
		n = (length - 1) / 2;
	else
		n = (length / 2);
	n++;

	for (length = n; str[length] != '\0'; length++)
	_putchar(str[length]);
	_putchar('\n');
}

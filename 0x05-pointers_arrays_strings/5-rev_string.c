#include "main.h"

/**
 * rev_string - reverses a string
 *
 * @s: string parameter input
 *
 * Return: 0
*/

void rev_string(char *s)
{
	int count = 0, i, length;
	char temp;

	while (s[count])
	{
		count++;
	}
	length = count - 1;
	for (i = 0; length >= 0 && i < length; length--, i++)
	{
		temp = s[i];
		s[i] = s[length];
		s[length] = temp;
	}
}

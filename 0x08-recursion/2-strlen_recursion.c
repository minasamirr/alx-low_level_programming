#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: The string for which to find the length.
 * Return: The length of the string.
*/
int _strlen_recursion(char *s)
{
	int i = 0;

	if (*s == '\0')
	{
		return (0);
	}
	return (i + _strlen_recursion(s + 1));
}

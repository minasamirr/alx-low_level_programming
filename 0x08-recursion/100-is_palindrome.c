#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: The string for which to find the length.
 * Return: The length of the string.
*/
int _strlen_recursion(char *s)
{
	int i = 0;

	if (*s)
	{
		i++;
		i += _strlen_recursion(++s);

	}
	return (i);
}
/**
 * palindrome_checker - check if s is palindrome.
 * @s: string base address.
 * @left: left index.
 * @right: rigth index.
 * Return: 1 if s is palindrome, 0 otherwise.
 */
int palindrome_checker(char *s, int left, int right)
{
	if (s[left] == s[right])
		if (left > right / 2)
			return (1);
		else
			return (palindrome_checker(s, ++left, --right));
	else
		return (0);
}
/**
 * is_palindrome - check if s is palindrome
 * @s: base address for string.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_palindrome(char *s)
{
	return (palindrome_checker(s, 0, _strlen_recursion(s) - 1));
}

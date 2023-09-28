#include "main.h"

/**
 * wildcmp_recursive - Helper function to compare two strings with '*'.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */
int wildcmp_recursive(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
	{
		if (*s1 == '\0')
		{
			return (wildcmp_recursive(s1, s2 + 1));
		}
		return (wildcmp_recursive(s1 + 1, s2) || wildcmp_recursive(s1, s2 + 1));
	}
	if (*s1 == *s2 || (*s2 == '?' && *s1 != '\0'))
		return (wildcmp_recursive(s1 + 1, s2 + 1));
	return (0);
}

/**
 * wildcmp - Compares two strings with '*' as a wildcard.
 * @s1: The first string to compare.
 * @s2: The second string to compare, which may contain '*'.
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_recursive(s1, s2));
}

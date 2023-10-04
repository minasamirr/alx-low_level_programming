#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *dup_str;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the input string */
	while (str[len] != '\0')
		len++;

	/* Allocate memory for the duplicated string */
	dup_str = malloc((len + 1) * sizeof(char));

	if (dup_str == NULL)
		return (NULL);

	/* Copy the input string to the duplicated string */
	for (i = 0; i <= len; i++)
		dup_str[i] = str[i];

	return (dup_str);
}

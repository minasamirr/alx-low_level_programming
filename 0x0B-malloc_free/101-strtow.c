#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: A pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);

	int word_count = 0, i = 0, j, k = 0;
	int len = strlen(str);

	/* Count the number of words */
	while (i < len)
	{
		while (i < len && str[i] == ' ')
			i++;
		if (i < len)
			word_count++;
		while (i < len && str[i] != ' ')
			i++;
	}

	if (word_count == 0)
		return (NULL);

	/* Allocate memory for the array of words */
	char **words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	while (i < len && k < word_count)
	{
		while (i < len && str[i] == ' ')
			i++;
		j = i;
		while (i < len && str[i] != ' ')
			i++;
		words[k] = malloc((i - j + 1) * sizeof(char));
		if (words[k] == NULL)
		{
			for (k = 0; k < word_count; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		strncpy(words[k], str + j, i - j);
		words[k][i - j] = '\0';
		k++;
	}
	words[k] = NULL;

	return (words);
}

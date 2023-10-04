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
	char **words;
	int i, j, k, word_count = 0, len = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	/* Count the number of words in the string */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			word_count++;
	}

	/* Allocate memory for the array of words */
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			len = 0;
			for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
				len++;
			words[k] = malloc((len + 1) * sizeof(char));
			if (words[k] == NULL)
			{
				for (k = 0; k < word_count; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}
			for (j = 0; j < len; j++, i++)
				words[k][j] = str[i];
			words[k][j] = '\0';
			k++;
		}
		else
		{
			i++;
		}
	}
	words[k] = NULL;

	return (words);
}

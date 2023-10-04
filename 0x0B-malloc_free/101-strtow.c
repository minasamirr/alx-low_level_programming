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
	int i, j, k, word_count = 0;
	int word_len = 0;
	int str_len = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	/* Calculate the total number of words in the string */
	str_len = strlen(str);
	for (i = 0; i < str_len; i++)
	{
		if (str[i] != ' ')
		{
			word_count++;
			while (str[i] != ' ' && str[i] != '\0')
			{
				word_len++;
				i++;
			}
		}
	}

	/* Allocate memory for the array of words */
	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	/* Allocate memory for each word and copy it */
	i = 0;
	k = 0;
	while (i < str_len && k < word_count)
	{
		if (str[i] != ' ')
		{
			j = 0;
			while (str[i] != ' ' && str[i] != '\0')
			{
				i++;
				j++;
			}
			words[k] = malloc((j + 1) * sizeof(char));
			if (words[k] == NULL)
			{
				for (k = 0; k < word_count; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}
			strncpy(words[k], str + i - j, j);
			words[k][j] = '\0';
			k++;
		}
		i++;
	}
	words[k] = NULL;

	return (words);
}

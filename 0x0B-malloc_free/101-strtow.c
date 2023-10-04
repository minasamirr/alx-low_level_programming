#include "main.h"
#include <stdlib.h>

char **split_words(char *str);
void free_word_array(char **words);
char *extract_word(char *str, int start, int end);

/**
 * split_words - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words), or NULL on failure.
 * Each element of the array contains a single word, null-terminated.
 * The last element of the array is NULL.
 */
char **split_words(char *str)
{
	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
	{
		return (NULL);
	}

	int len = 0;
	int num_words = 0;
	int in_word = 0;

	while (str[len])
	{
		if (!in_word && str[len] != ' ')
		{
			in_word = 1;
			num_words++;
		}
		else if (in_word && str[len] == ' ')
		{
			in_word = 0;
		}
		len++;
	}

	if (in_word)
	{
		num_words++;
	}

	if (num_words == 0)
	{
		return (NULL);
	}

	char **words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}

	int i = 0;
	int start = 0;

	for (int j = 0; j < len; j++)
	{
		if (!in_word && str[j] != ' ')
		{
			start = j;
			in_word = 1;
		}
		else if (in_word && str[j] == ' ')
		{
			in_word = 0;
			words[i++] = extract_word(str, start, j);
		}
	}

	if (in_word)
	{
		words[i++] = extract_word(str, start, len);
	}

	words[i] = NULL;

	return (words);
}

/**
 * extract_word - Extracts a word from a string.
 * @str: The input string.
 * @start: The starting index of the word.
 * @end: The ending index of the word.
 *
 * Return: A pointer to the extracted word.
 */
char *extract_word(char *str, int start, int end)
{
	int length = end - start;
	char *word = (char *)malloc((length + 1) * sizeof(char));

	if (word == NULL)
	{
		return (NULL);
	}

	for (int i = 0; start < end; start++, i++)
	{
		word[i] = str[start];
	}

	word[length] = '\0';

	return (word);
}

/**
 * free_word_array - Frees the memory allocated for an array of words.
 * @words: The array of words.
 */
void free_word_array(char **words)
{
	if (words == NULL)
	{
		return;
	}

	for (int i = 0; words[i] != NULL; i++)
	{
		free(words[i]);
	}

	free(words);
}

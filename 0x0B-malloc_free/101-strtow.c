#include <stdlib.h>
#include <stdio.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The count of words in the string.
 */
int count_words(char *str);

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words).
 *         Each element of the array contains a single word, null-terminated.
 *         The last element of the returned array is set to NULL.
 *         Returns NULL if str == NULL or str == "".
 *         Returns NULL if memory allocation fails.
 */
char **strtow(char *str);

/**
 * is_space - Checks if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if c is a whitespace character, 0 otherwise.
 */
int is_space(char c);

/**
 * strtow - splits a string into words.
 * @str: the string
 *
 * Return: returns a pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	/* Check for NULL or empty string */
	if (str == NULL || *str == '\0')
		return (NULL);

	/* Count the number of words in the input string */
	int word_count = count_words(str);

	if (word_count == 0)
		return (NULL);

	/* Allocate memory for an array of strings (words) */
	char **words = (char **)malloc((word_count + 1) * sizeof(char *));

	if (words == NULL)
		return (NULL);

	int word_index = 0;
	int start = 0;
	int end = 0;

	/* Split the string into words and store them in the array */
	while (str[start] != '\0')
	{
		/* Skip leading whitespace */
		while (is_space(str[start]))
			start++;
		end = start;

		/* Find the end of the current word */
		while (str[end] != '\0' && !is_space(str[end]))
			end++;

		int word_length = end - start;

		/* Allocate memory for the word and copy it */
		words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
		if (words[word_index] == NULL)
		{
			/* Free memory and return NULL if allocation fails */
			for (int i = 0; i < word_index; i++)
				free(words[i]);
			free(words);
			return (NULL);
		}

		/* Copy the word */
		for (int i = 0; i < word_length; i++)
			words[word_index][i] = str[start + i];

		words[word_index][word_length] = '\0';

		start = end;
		word_index++;
	}

	/* Set the last element of the array to NULL */
	words[word_index] = NULL;
	return (words);
}

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The count of words in the string.
 */
int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (!is_space(str[i]))
		{
			count++;
			while (str[i] != '\0' && !is_space(str[i]))
				i++;
		}
		else
		{
			i++;
		}
	}

	return (count);
}

/**
 * is_space - Checks if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if c is a whitespace character, 0 otherwise.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

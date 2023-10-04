#include "main.h"
#include <stdlib.h>

int count_words(char *str);
void create_words(char **words, char *str, int num_words);
int is_whitespace(char c);

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words), or NULL on failure.
 * Each element of the array contains a single word, null-terminated.
 * The last element of the array is NULL.
 */
char **strtow(char *str)
{
	int num_words, i = 0, in_word = 0, start = 0, word_index = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (str[i])
	{
		if (!in_word && !is_whitespace(str[i]))
		{
			start = i;
			in_word = 1;
		}
		else if (in_word && is_whitespace(str[i]))
		{
			in_word = 0;
			create_words(words, str + start, i - start);
			word_index++;
		}
		i++;
	}

	if (in_word)
		create_words(words, str + start, i - start);

	words[word_index] = NULL;

	return (words);
}

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (is_whitespace(*str))
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * create_words - Creates a word and inserts it into the array.
 * @words: The array of strings.
 * @str: The string containing the word.
 * @length: The length of the word.
 */
void create_words(char **words, char *str, int length)
{
	int i;

	words[0] = (char *)malloc((length + 1) * sizeof(char));
	if (words[0] == NULL)
		return;

	for (i = 0; i < length; i++)
	{
		words[0][i] = str[i];
	}
	words[0][length] = '\0';
}

/**
 * is_whitespace - Checks if a character is whitespace.
 * @c: The character to check.
 *
 * Return: 1 if c is whitespace, 0 otherwise.
 */
int is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

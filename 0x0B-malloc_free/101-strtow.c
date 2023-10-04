#include "main.h"
#include <stdlib.h>

char **split_words(char *str);
void free_word_array(char **words);
char *extract_word(char *str, int start, int end);

char **split_words(char *str)
{
	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
	{
		return NULL;
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
		return NULL;
	}

	char **words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
	{
		return NULL;
	}

	int i = 0;
	int start = 0;
	int j = 0;

	while (str[j])
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
		j++;
	}

	if (in_word)
	{
		words[i++] = extract_word(str, start, j);
	}

	words[i] = NULL;

	return (words);
}

char *extract_word(char *str, int start, int end)
{
	int length = end - start;
	char *word = (char *)malloc((length + 1) * sizeof(char));

	if (word == NULL)
	{
		return NULL;
	}

	int i = 0;

	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}

	word[length] = '\0';

	return (word);
}

void free_word_array(char **words)
{
	if (words == NULL)
	{
		return;
	}

	int i = 0;

	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}

	free(words);
}

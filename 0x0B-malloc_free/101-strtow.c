#include "main.h"
#include <stdlib.h>

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
    int i, flag, len;
    char **words;

    if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
    {
        return NULL;
    }

    i = flag = len = 0;
    while (str[i])
    {
        if (flag == 0 && str[i] != ' ')
        {
            flag = 1;
        }
        if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
        {
            flag = 0;
            len++;
        }
        i++;
    }

    len += flag == 1 ? 1 : 0;
    if (len == 0)
    {
        return NULL;
    }

    words = (char **)malloc(sizeof(char *) * (len + 1));
    if (words == NULL)
    {
        return NULL;
    }

    util(words, str);
    words[len] = NULL;
    return words;
}


/**
 * util - A utility function for fetching words into an array.
 * @words: The array of strings.
 * @str: The input string.
 */
void util(char **words, char *str)
{
    int i, j, start, flag;

    i = j = flag = 0;
    while (str[i])
    {
        if (flag == 0 && str[i] != ' ')
        {
            start = i;
            flag = 1;
        }

        if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
        {
            create_word(words, str, start, i, j);
            j++;
            flag = 0;
        }

        i++;
    }

    if (flag == 1)
    {
        create_word(words, str, start, i, j);
    }
}

/**
 * create_word - Creates a word and inserts it into the array.
 * @words: The array of strings.
 * @str: The input string.
 * @start: The starting index of the word.
 * @end: The stopping index of the word.
 * @index: The index of the array to insert the word.
 */
void create_word(char **words, char *str, int start, int end, int index)
{
    int i, j;

    i = end - start;
    words[index] = (char *)malloc(sizeof(char) * (i + 1));

    for (j = 0; start < end; start++, j++)
    {
        words[index][j] = str[start];
    }
    words[index][j] = '\0';
}

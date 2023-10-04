#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program
 * @ac: The argument count
 * @av: The argument vector (array of strings)
 *
 * Return: A pointer to the concatenated string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *concat_str;
	int i, j, len = 0;
	int total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the total length of the concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		total_len += len + 1; /* +1 for the newline character */
		len = 0;
	}

	/* Allocate memory for the concatenated string */
	concat_str = malloc((total_len + 1) * sizeof(char));

	if (concat_str == NULL)
		return (NULL);

	/* Copy each argument followed by '\n' to the concatenated string */
	len = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			concat_str[len] = av[i][j];
			len++;
		}
		concat_str[len] = '\n';
		len++;
	}
	concat_str[len] = '\0';

	return (concat_str);
}

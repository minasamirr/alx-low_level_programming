#include "main.h"

/**
 * _strncat - concatenates two strings
 *
 * @src: The source of strings
 * @dest: The destination of the string
 * @n: The length of int
 * Return: pointer to the resulting string dest
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i])
		i++;

	for (j = 0; src[j] ; j++)
		dest[i++] = src[j];

	return (dest);
}

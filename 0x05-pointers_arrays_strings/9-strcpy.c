#include "main.h"

/**
 * _strcpy - copy the string pointed to by src to dest
 *
 * @dest: char to check
 * @src: char to check
 * Return: pointer to dest input parameter
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

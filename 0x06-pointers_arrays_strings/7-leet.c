#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: address of str
 */
char *leet(char *str)
{
	int i, j;
	char a[] = "aAeEoOtTlL";
	char b[] = "4433007711";

	for (i = 0; *(str + i); i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[j] == str[i])
				str[i] = b[j];
		}
	}
	return (str);
}

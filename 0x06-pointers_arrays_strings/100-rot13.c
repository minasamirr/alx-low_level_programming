#include "main.h"

/**
 * rot13 - encodes a string into rot13
 * @s: string to encode
 * Return: address of s
*/
char *rot13(char *s)
{
	int i, j;
	char prim[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char shifted[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; *(s + i); i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (prim[j] == *(s + i))
			{
				*(s + i) = shifted[j];
				break;
			}
		}
	}
	return (s);
}

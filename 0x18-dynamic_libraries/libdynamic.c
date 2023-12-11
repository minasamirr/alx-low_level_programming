#include "main.h"

/**
 * __putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
*/

int _putchar(char c);

/**
 * _islower - function to check if character is lowercase
 *
 * @c: number which is input of function
 *
 * Return: returns 1 if `c` is lowercase
 *         otherwise always 0 (Success)
*/

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

/**
 * _isalpha - checks if character is a letter both lowercase or uppercase
 *
 * from 97 to 122 lowercase
 * from 65 to 90  uppercase
 *
 * @c: takes input from other functions.
 *
 * Return: 1 is c if true else 0
*/

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

/**
 * _abs - function that computes the absolute value of an integer
 *
 * @n: integer type input for function
 *
 * Return: Always 0 (Success)
*/

int _abs(int n)
{
	if (n < 0)
		n = (-1) * n;
	return (n);
}

/**
 * _isupper - uppercase letters
 * @c: character to check
 *
 * Return: 0 or 1
 */

int _isupper(int c)
{
	if ((c >= 65) && (c <= 90))
		return (1);
	return (0);
}

/**
* _isdigit - write a function that check for a digit (0 through 9).
* @c: char to check
* Return:  0 or 1
**/
int _isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

/**
 * _strlen - returns the length of a string
 *
 * @s: string parameter input
 *
 * Return: length of string
*/

int _strlen(char *s)
{
	int count;

	for (count = 0; *s != '\0'; s++)
		count++;

	return (count);
}

/**
 * _puts - prints a string, followed by a new line to stdout
 *
 * @str: string parameter to print
 *
 * Return: 0
*/

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		str++;
	}
	_putchar('\n');
}

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

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * we multiple the num by 10 to shift it to the left
 * then we subtract '0' ASCII code from the char to convert it to number
 * Return: integer
 */

int _atoi(char *s)
{
	int i = 1;
	unsigned int num = 0;

	do {
	if (*s == '-')
		i *= -1;

	else if (*s >= '0' && *s <= '9')
		num = num * 10 + (*s - '0');
	else if (num > 0)
		break;
	} while (*s++);

	return (num * i);
}

/**
 * _strcat - concat 2 string
 *
 * @dest:char
 * @src:char
 * Return:char
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i])
		i++;
	for (j = 0; src[j]; j++)
		dest[i++] = src[j];

	return (dest);
}

/**
 * _strncat - concatenates two strings
 *
 * @src: The source of strings
 * @dest: The destination of the string
 * @n: The length of int
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		continue;
	for (j = 0; src[j] != '\0' && j < n; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';

	return (dest);
}

/**
 *_strncpy - function that copies a string
 *
 * @src: The source of strings
 * @dest: The destination of the string
 * @n: The length of int
 *
 * Return: pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

/**
 * _strcmp - compare 2 string
 * @s1:string
 * @s2:strmp
 *
 * Return:int
 */
int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _memset - Fills the first n bytes of the memory area pointed to by s
 *           with the constant byte b.
 * @s: A pointer to the memory area to be filled.
 * @b: The constant byte to fill the memory with.
 * @n: The number of bytes to fill.
 *
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest.
 * @dest: Pointer to the destination memory area.
 * @src: Pointer to the source memory area.
 * @n: Number of bytes to copy.
 *
 * Return: A pointer to the destination memory area (dest).
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}

/**
 * _strchr - Locates a character in a string.
 * @s: Pointer to the string to search in.
 * @c: The character to locate.
 *
 * Return: A pointer to the first occurrence of the character c in the string s
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			s++;
		else
			return (s);
	}
	if (c == '\0')
		return (s);

	return (NULL);
}

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: Pointer to the string to search.
 * @accept: Pointer to the string containing characters to match.
 *
 * Return: The number of bytes in the initial segment of s which consist only
 *         of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j, k = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != 32)
		{
			for (j = 0; accept[j] != '\0'; j++)
			{
				if (s[i] == accept[j])
					k++;
			}
		}
		else
			return (k);
	}
		return (k);

}


/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: Pointer to the string to search.
 * @accept: Pointer to the string containing bytes to search for.
 *
 * Return: A pointer to the byte in s that matches one of the bytes in accept,
 *         or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	int i;
		while (*s)
		{
			for (i = 0; accept[i]; i++)
			{
				if (*s == accept[i])
					return (s);
			}
			s++;
		}
	return (NULL);
}

/**
 * _strstr - Locates a substring in a string.
 * @haystack: Pointer to the string to search in.
 * @needle: Pointer to the substring to search for.
 *
 * Return: A pointer to the beginning of the located substring, or NULL
 *         if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;

	while (haystack[i])
	{
		while (needle[j] && (haystack[i] == needle[0]))
		{
			if (haystack[i + j] == needle[j])
				j++;
			else
				break;
		}
		if (needle[j])
		{
			i++;
			j = 0;
		}
		else
			return (haystack + i);
	}
	return (0);
}

#include "main.h"

/*
 * infinite_add - add two numbers
 * Parameters:
 * n1 - the first number as a string
 * n2 - the second number as a string
 * r - the buffer to store the result
 * size_r - the size of the result buffer
 * Returns:
 * A pointer to the result or NULL if the result cannot fit in the buffer
*/
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1),  len2 = strlen(n2);
	int carry = 0;
	int i = len1 - 1;
	int j = len2 - 1;
	int k = 0;

	if (size_r <= len1 || size_r <= len2)
	{
		return (NULL);
	}

	while (i >= 0 || j >= 0 || carry > 0)
	{
		int digit1 = (i >= 0) ? n1[i] - '0' : 0;
		int digit2 = (j >= 0) ? n2[j] - '0' : 0;
		int sum = digit1 + digit2 + carry;

		carry = sum / 10;
		r[k] = '0' + (sum % 10);
		i--;
		j--;
		k++;

		if (k >= size_r)
		{
			return (NULL);
		}
	}

	r[k] = '\0';

	for (int start = 0, end = k - 1; start < end; start++, end--)
	{
		char temp = r[start];

		r[start] = r[end];
		r[end] = temp;
	}

	return (r);
}

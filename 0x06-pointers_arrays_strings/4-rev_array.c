#include "main.h"

/**
 * reverse_array - reverse array
 * @a:array
 * @n:integer
 * Return:void
*/
void reverse_array(int *a, int n)
{
	int i, j, temp;
	j = n-1;

	for (i = 0; i < n / 2; i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

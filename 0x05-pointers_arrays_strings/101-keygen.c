#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for the
 *        program 101-crackme.
 *
 * Return: Always 0.
 */
int main(void)
{
	char password[84];
	int i = 0, sum_num = 0, pass_half1, pass_half2;

	srand(time(0));

	while (sum_num < 2772)
	{
		password[i] = 33 + rand() % 94;
		sum_num += password[i++];
	}

	password[i] = '\0';

	if (sum_num != 2772)
	{
		pass_half1 = (sum_num - 2772) / 2;
		pass_half2 = (sum_num - 2772) / 2;
		if ((sum_num - 2772) % 2 != 0)
			pass_half1++;

		for (i = 0; password[i]; i++)
		{
			if (password[i] >= (33 + pass_half1))
			{
				password[i] -= pass_half1;
				break;
			}
		}
		for (i = 0; password[i]; i++)
		{
			if (password[i] >= (33 + pass_half2))
			{
				password[i] -= pass_half2;
				break;
			}
		}
	}

	printf("%s", password);

	return (0);
}

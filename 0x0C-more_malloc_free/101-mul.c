#include "main.h"

/**
 * print_result - Print the result without leading zeroes
 * @result: The result as a string
 */
void print_result(char *result)
{
    int i = 0;
    while (result[i] == '0' && result[i + 1] != '\0')
    {
        i++;
    }

    while (result[i] != '\0')
    {
        _putchar(result[i]);
        i++;
    }

    _putchar('\n');
}

/**
 * multiply_single_digit - Multiply a single digit by a string of digits
 * @digit: The single digit
 * @num: The string of digits to multiply
 * @result: The result string
 * @result_index: The starting index for the result
 *
 * Return: 1 if multiplication is successful, 0 on failure
 */
int multiply_single_digit(char digit, char *num, char *result, int result_index)
{
    int carry = 0;
    int digit_int = digit - '0';
    int num_len = strlen(num);

    for (int i = num_len - 1; i >= 0; i--)
    {
        int product = (num[i] - '0') * digit_int + carry;
        carry = product / 10;
        result[result_index] = (product % 10) + '0';
        result_index--;
    }

    if (carry != 0)
    {
        return 0; // Multiplication resulted in overflow
    }

    return 1;
}

/**
 * multiply - Multiply two positive numbers represented as strings
 * @num1: The first number as a string
 * @num2: The second number as a string
 *
 * Return: The result of the multiplication as a string
 */
char *multiply(char *num1, char *num2)
{
    if (num1 == NULL || num2 == NULL || !is_positive_integer(num1) || !is_positive_integer(num2))
    {
        return NULL; // Invalid input
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int result_len = len1 + len2;

    char *result = malloc((result_len + 1) * sizeof(char));
    if (result == NULL)
    {
        perror("Memory allocation failed");
        exit(98);
    }

    for (int i = 0; i < result_len; i++)
    {
        result[i] = '0'; // Initialize result to '0'
    }
    result[result_len] = '\0';

    for (int i = len1 - 1; i >= 0; i--)
    {
        if (!multiply_single_digit(num1[i], num2, result, i + len2))
        {
            free(result);
            return NULL; // Multiplication resulted in overflow
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 3 || !is_positive_integer(argv[1]) || !is_positive_integer(argv[2]))
    {
        printf("Error\n");
        return 98;
    }

    char *num1 = argv[1];
    char *num2 = argv[2];

    char *result = multiply(num1, num2);

    if (result != NULL)
    {
        print_result(result);
        free(result);
    }
    else
    {
        printf("Error\n");
        return 98;
    }

    return 0;
}

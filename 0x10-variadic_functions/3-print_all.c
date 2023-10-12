#include "variadic_functions.h"


/**
 * print_all - prints anything based on the format
 * @format: a list of types of arguments
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	char *separator = "";
	unsigned int i = 0;
	va_list args;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", separator, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", separator, (float)va_arg(args, double));
				break;
			case 's':
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(nil)";
				printf("%s%s", separator, str);
				break;
			}
			default:
				i++;
				continue;
		}

		separator = ", ";
		i++;
	}

	va_end(args);
	printf("\n");
}

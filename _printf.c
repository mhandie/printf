#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - Prints output according to a format
 * @format: Is a character.
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings)
 **/
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	int i;
	char *str;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c':
					{
						char c = va_arg(args, int);
						write(1, &c, 1);
						printed_chars++;
					}
					break;

				case 's':
					{
						str = va_arg(args, char *);
						if (str == NULL)
							str = "(null)";
						while (*str)
						{
							write(1, str, 1);
							str++;
							printed_chars++;
						}
					}
					break;

				case '%':
					write(1, "%", 1);
					printed_chars++;
					break;

				default:
					write(1, "%", 1);
					write(1, &format[i], 1);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
	}

	va_end(args);

	return printed_chars;
}

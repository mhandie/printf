#include "main.h"

/**
 * _printf - Prints output according to a format
 * @format: Is a character.
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings)
 **/
int _printf(const char *format, ...)
{
	int chars_printed = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':
					{
						int c = va_arg(args, int);

						chars_printed += write(1, &c, 1);
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char *);

						chars_printed += write(1, s, strlen(s));
						break;
					}
				case '%':
					{
						chars_printed += write(1, "%", 1);
						break;
					}
				default:
					{
						break;
					}
			}
		}
		else
		{
			chars_printed += write(1, format, 1);
		}

		format++;
	}

	va_end(args);

	return (chars_printed);
}

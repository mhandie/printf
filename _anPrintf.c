#include "main.h"
#include <stdio.h>

/**
 * _printf - Prints output according to a format.
 * @format: A pointer to a character.
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int chars_printed = 0;
	va_list args;

	if (format == NULL)
		return (-1);

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

					chars_printed += _write_char(c);
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);

					chars_printed += fwrite(s, 1, strlen(s), stdout);
					break;
				}
				case '%':
				{
					chars_printed += putchar('%');
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
			chars_printed += putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (chars_printed);
}

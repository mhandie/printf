#include "main.h"
/**
 * int _printf- handle the conversion specifiers
 *
 * @format: formatted string
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int len = 0;

	va_start(arg_list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd' || *format == 'i')
			{
				int number = va_arg(arg_list, int);
				len += printf("%d", number);
			}
			else
			{
				len += printf("%%");
			}
		}
		else
		{
			len += printf("%c", *format);
		}
		format++;
	}
	va_end(arg_list);
	return len;
}


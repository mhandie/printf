#include "main.h"

/**
 * get_string_length - Calculates the length of the string
 * @str: The string to be calculated
 *
 * Return: The length of the string
 **/
int get_string_length(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}

/**
 * _printf - Produces output according to a format
 * @format: Is a character, string.
 *
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings)
 **/
int _printf(const char *format, ...)
{
	int size;
	va_list args;

	if (format == NULL)
		return (-1);

	size = get_string_length(format);
	if (size <= 0)
		return (0);

	va_start(args, format);
	size = handler(format, args);

	_putchar(-1);
	va_end(args);

	return (size);
}

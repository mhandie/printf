#include "main.h"
#include <stdarg.h>
#include <stdarg.h>

/**
 * print_integer - prints integer
 * @list: list of arguments passed
 * Return: number of characters printed
 */
int print_integer(va_list list)
{
int num = va_arg(list, int);

int len = 0;
if (num < 0)
{
_write_char('-');
len++;
num = -num;
}
len += print_number(num);
return len;
}

/**
 * unsigned_integer - prints unsigned integers
 * @list: list of arguments passed
 * Return: number of characters printed
 */
int unsigned_integer(va_list list)
{
unsigned int num = va_arg(list, unsigned int);
return print_unsgined_number(num);
}

#include "main.h"

/**
 * print_char - character
 * @list: arguments passed
 * Return: characters printed
 */
int main(void);

int print_char(va_list list)
{
_write_char(va_arg(list, int));
return (1);
}

/**
 * print_string - string
 * @list: arguments passed
 * Return: characters printed
 */
int print_string(va_list list)
{
char *str = va_arg(list, char *);

int len = 0;
if (str == NULL)
str = "(null)";
while (*str != '\0')
{
_write_char(*str);
str++;
len++;
}
return (len);
}

/**
 * print_percent - percent
 * @list: arguments passed
 * Return: characters printed
 */
int print_percent(va_list list)
{
(void)list;
_write_char('%');
return (1);
}

/**
 * print_integer - prints integer
 * @list: list of arguments passed
 * Return: number of characters printed
 */

int num = va_arg(list, int);

int len = 0;
if (num < 0)
{
_write_char('-');
len++;
num = -num;
}
len += print_number(len);
return (len);
}

/**
 * unsigned_integer - unsigned integers
 * @list: arguments passed
 * Return: characters printed
 */
int unsigned_integer(va_list list)
{
unsigned int num = va_arg(list, unsigned int);
return (print_unsgined_number(num));
}

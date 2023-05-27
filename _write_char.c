#include "main.h"

/**
 * _putchar - prints a character
 * @c: The character to print
 *
 * Return: 1 on a success
 * On error, -1 is returned
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

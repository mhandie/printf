#include "main.h"

/**
 * _write_char - prints a character
 * @c: The character to print
 *
 * Return: 1 on a success
 * On error, -1 is returned
 */

int _write_char(char c)
{
	return (write(1, &c, 1));
}

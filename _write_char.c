#include "main.h"

/**
 * _write_char - prints character "c"
 * @c: character variable
 * Return: 1 (success) and -1
 */

int _write_char(char c)
{
	return (write(1, &c, 1));
}

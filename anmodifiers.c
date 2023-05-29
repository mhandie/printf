#include "main.h"

unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid);

/**
 * print_width - a width modifier.
 * @output: a character array.
 * @printed: characters to output
 * @flags: flag modifiers.
 * @wid: width modifier.
 *
 * Return: bytes stored
 */
unsigned int print_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_string_width - a width modifier.
 * @output: struct containing a character array.
 * @flags: flag modifiers.
 * @wid: width modifier.
 * @prec: precision modifier.
 * @size: size of string.
 *
 * Return:  bytes stored
 */
unsigned int print_string_width(buffer_t *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_neg_width - trailing spaces stored
 * @output: struct containing a character array.
 * @printed: bytes stored to output
 * @flags: flag modifiers.
 * @wid: width modifier.
 *
 * Return: bytes stored
 */
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * int print_char - prints character "c"
 * @c: character variable
 * Return:  _write_char
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
return _write_char(c);
}

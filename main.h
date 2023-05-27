#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE
#include <stdarg.h> /* variadic functions that accept a variable number of arguments*/
#include <stdio.h> /*input/output operations, such as printf and file I/O functions*/
#include <unistd.h> /*provides access to file I/O operations like write */
#define UNUSED(x) (void)(x) /* casts the variable x to void*/
#define BUFF_SIZE 1024 /*defines the buffer size with a value of 1024. */

/* MACROS*/
#define S_LONG 2 /* a value of 2*/
#define S_SHORT 1 /* a value of 1*/
#define F_MINUS 1 /*This macro is defined with a value of 1. */
#define F_PLUS 2 /*This macro is defined with a value of 2 */
#define F_ZERO 4 /*This macro is defined with a value of 4 */
#define F_HASH 8 /*This macro is defined with a value of 8 */
#define F_SPACE 16 /*This macro is defined with a value of 16 */

/**
* struct fmt - Struct
*
* @fmt: a format character specifier.
* @fn: a function pointer.
*/
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
* typedef struct fmt fmt_t - Struct op
*
* @fmt: a format character specifier.
* @fm_t: function
*/
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*THE FUNCTIONS*/
/* Functions that print characters and strings */
int print_char(va_list types, char buffer[], /* A va_list object contains the arguments.*/
int flags, int width, int precision, int size); /* integer representing flags or format options*/
int print_string(va_list types, char buffer[], /* character array where output will be stored*/
int flags, int width, int precision, int size);/* integer representing flags or format options*/
int print_percent(va_list types, char buffer[],/* print a percentage value*/
int flags, int width, int precision, int size); /* integer representing flags or format options*/

/* Functions for width handler */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);

/* Functions that print out numbers */
int print_int(va_list types, char buffer[],  /* character array where output will be stored*/
int flags, int width, int precision, int size);/* integer representing flags or format options*/
int print_binary(va_list types, char buffer[]  /* char array where binary output will be stored*/
int flags, int width, int precision, int size); /* integer representing flags or format options*/
int print_unsigned(va_list types, char buffer[],  /* character array for unsigned output*/
int flags, int width, int precision, int size); /* integer representing flags or format options*/
int print_octal(va_list types, char buffer[], /*function to format and print an octal value */
int flags, int width, int precision, int size); /* integer representing flags or format options*/
int print_hexadecimal(va_list types, char buffer[], /*function meant for hexadecimal value */
int flags, int width, int precision, int size); /* integer representing flags or format options*/
int print_hexa_upper(va_list types, char buffer[], /*format & print uppercase hexadecimal*/
int flags, int width, int precision, int size); /* integer representing flags or format options*/
int print_hexa(va_list types, char map_to[], /*format and print a hexadecimal value*/
char buffer[], int flags, char flag_ch, int width, int precision, int size); /*used as buffer to store */

/* Functions that print out non-printable characters */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Functions that print out memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Functions that handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Functions that print string in reverse*/
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Functions that print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Other function declarations*/
int is_printable(char); /*to determin if character is printatble*/
int append_hexa_code(char, char[], int); /* used to append a hexadecimal code */
int is_digit(char); /*checks if character reps a digit r not*/
long int convert_size_number(long int num, int size);/*convert num from one size to other*/
long int convert_size_unsgnd(unsigned long int num, int size); /*takes an unsigned long integer as an argument.*/

#endif


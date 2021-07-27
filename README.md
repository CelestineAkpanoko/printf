# printf

# Description
This team project is part of the first trimester curriculum of the ALX Programme . The _printf function prints output to the standard output in a formatted form.

# Project Requirements
All files will be compiled on Ubuntu 14.04 LTS <br />
Programs and functions will be compiled with gcc 4.8.4 using flags -Wall -Werror -Wextra and -pedantic compiler <br />
Code must follow the Betty style <br />
Global variables are not allowed<br />
Authorized functions and macros:<br />
write (man 2 write) <br />
malloc (man 3 malloc) <br />
free (man 3 free) <br />
va_start (man 3 va_start)<br />
va_end (man 3 va_end)<br />
va_copy (man 3 va_copy)<br />
va_arg (man 3 va_arg)<br />

# File Description
print_numbers.c: - contains the functions print_i and print_d, which handle the conversion specifiers i and d, respectively<br />
print_hex.c: - contains the functions print_hex, which prints an unsigned int in hexidecimal form, print_x, print_X, and print_p, which handle the conversion specifiers x, X, and p, respectively <br />
print_unsigned_int.c: - contains the functions print_u, print_o, and print_b, which handle the conversion specifiers u, o, and b, respectively<br />
_printf.c: - contains the fucntion _printf, which uses the prototype int _printf(const char *format, ...);. The format string is composed of zero or more directives. See man 3 printf for more detail. _printf will return the number of characters printed (excluding the null byte used to end output to strings) and will write output to stdout, the standard output stream.<br />
_putchar.c: - contains the function _putchar, which writes a character to stdout.<br />
holberton.h: - contains all function prototypes used for _printf.<br />
man_3_printf: - manual page for the custom _printf function.<br />
print_chars.c: - contains the functions print_c, print_s, print_S, and print_r which handle the conversion specifiers c, s, S, and r, respectively, as well as hex_print, which prints a char's ascii value in uppercase hex

# Mandatory Tasks
Write function that produces output with conversion specifiers c, s, and %.<br />
Handle conversion specifiers. d, i.<br />
Create a man page for your function.<br />

# Advanced Tasks<br />
Handle conversion specifier b.<br />
Handle conversion specifiers u, o, x, X.<br />
Use a local buffer of 1024 chars in order to call write as little as possible.<br />
Handle conversion specifier S.<br />
Handle conversion specifier p.<br />
Handle flag characters +, space, and # for non-custom conversion specifiers.<br />
Handle length modifiers l and h for non-custom conversion specifiers.<br />
Handle the field width for non-custom conversion specifiers.<br />
Handle the precision for non-custom conversion specifiers.<br />
Handle the 0 flag character for non-custom conversion specifiers.<br />
Handle the custom conversion specifier r that prints the reversed string.<br />
Handle the custom conversion specifier R that prints the rot13'ed string.<br />
All above options should work well together.

# Team

Celestine Akpanoko.<br />
Udo Godslove.<br />

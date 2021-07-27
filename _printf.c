#include "holberton.h"

void cleaner(va_list ap, buffer_t *output);
int execute_printf(const char *format, va_list ap, buffer_t *output);
/* just for task 0 */
unsigned int (*specifiers_handler_task0(const char *specifier))(va_list, buffer_t *);

/**
 * cleaner - cleans up _printf
 * @ap: argument parameter from va_list provided to _printf
 * @output: buffer_t struct
 */
void cleaner(va_list ap, buffer_t *output)
{
	va_end(ap);
	write(1, output->start, output->len);
	free_buffer(output);
}
/**
 * execute_printf - reads through the format string for _printf to stdout
 * @format: character string to print
 * @output: buffer_t struct containing a buffer.
 * @ap: argument parameters of va_list
 *
 * Return: number of characters stored to output
 */
int execute_printf(const char *format, va_list ap, buffer_t *output)
{
	int i, width, precision, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *, unsigned char,
			int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = flags_handler(format + i + 1, &tmp);
			width = width_handler(ap, format + i + tmp + 1, &tmp);
			precision = precision_handler(ap, format + i + tmp + 1,
					&tmp);
			len = length_handler(format + i + tmp + 1, &tmp);

			f = specifiers_handler(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(ap, output, flags, width, precision, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleaner(ap, output);
	return (ret);
}
unsigned int (*specifier_handler_task0(const char *specifier))(va_list, buffer_t *)
{
	int i;
	converter_t0 converters[] = {
		{'c', convert_c0},
		{'s', convert_s0},
		{0, NULL}
	};

	for (i = 0; converters[i].func; i++)
	{
		if (converters[i].specifier == *specifier)
			return (converters[i].func);
	}

	return (NULL);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list ap;
	int ret, i;
	char tmp;
	unsigned int (*f)(va_list, buffer_t *);

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(ap, format);

	/* ret = execute_printf(format, args, output); */
	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			tmp = 0;
			f = specifier_handler_task0(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(ap, output);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}

				ret += _memcpy(output, (format + i), 1);
				/* i += (len != 0) ? 1 : 0; */
			}
		}
		
	

	cleaner(ap, output);
	return (ret);
}
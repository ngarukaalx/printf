#include "convert.h"
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - a function that produces output according to a format.
 * @format:character string
 *
 * Return:characters.
 */

int _printf(const char *format, ...)
{
	convert_match m[] = {
	{"%s", printf_string}, {"%c", printf_char},
	{"%%", printf_20},
	{"%i", printf_int},
	{"%d", printf_int},
	{NULL, NULL}
};

	va_list args;
	int k = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[k] != '\0')
	{
		j = 3;
		while (j >= 0)
		{
			if (m[j].specifier[0] == format[k] && m[j].specifier[1] == format[k + 1])
			{
				len += m[j].f(args);
				k = k + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[k]);
		len++;
		k++;
	}
	va_end(args);
	return (len);
}

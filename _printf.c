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
	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 3;
		while (j >= 0)
		{
			if (m[j].specifier[0] == format[i] && m[j].specifier[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}

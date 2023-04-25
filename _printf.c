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

	int len = 0;

	int i;

	int match_found = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			match_found = 0;
			for (i = 0; i < NUM_CONVERT_MATCHES; i++)
			{
				if (strncmp(format,
					m[i].specifier,2) == 0)
				{
					match_found = 1;
					len += m[i].f(args);
					format += 2;
					break;
				}
			}
			if (!match_found)
			{
				len += _putchar('%');
				if (*format != '%')
				{
					len += _putchar(*format);
					format++;
				}
			}
		}
		else
		{
			len += _putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (len);
}

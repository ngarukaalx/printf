#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					len += printf_char(args);
					break;
				case 's':
					len += printf_exclusive_string(args);
					break;
				case '%':
					len += printf_37();
					break;
				default:
					_putchar('%');
					if(*format)
					{
						_putchar(*format++);
						len += 2;
					}
					else
						len += 1;
					continue;
			}
			format++;
		}
		else
		{
			_putchar(*format++);
			len++;
		}
	}
	va_end(args);
	return (len);
}

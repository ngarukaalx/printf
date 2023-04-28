#include "convert.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * printf_string - prints string
 * @arg:parameter being checked
 * Return:string
 */

int printf_string(va_list arg)
{
	char *str = va_arg(arg, char*);
	int len = 0;

	while (*str)
	{
		_putchar(*str++);
		len++;
	}
	return (len);

}

/**
 * printf_char - print char
 * @arg:parameter being checked
 * Return:printed character
 */

int printf_char(va_list arg)
{
	char c = va_arg(arg, int);

	_putchar(c);
	return (1);
}

/**
 * printf_20 - print interger value
 * @arg:parameter being checked
 * Return:characters printed
 */

int printf_20(va_list arg)
{
	int value = va_arg(arg, int);

	printf("%d", value);
	return (1);
}

/**
 * printf_int - print int
 * @arg:parameter being checked
 * Return:string
 */
int printf_int(va_list arg)
{
	int n = va_arg(arg, int);

	int num, last = n % 10, digit, exp = 1;

	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}

/**
 * binary_print - prints binary
 * @val:arg
 *
 * Return:on sucess 1
 */

int binary_print(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}

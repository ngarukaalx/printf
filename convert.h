#ifndef CONVERT_H
#define CONVERT_H

#include <stdarg.h>

/**
 * struct convert_match - specifier
 */

typedef struct convert_match
{
	char *specifier;
	int (*f)(va_list);
} convert_match;
int printf_string(va_list args);
int printf_char(va_list args);
int printf_20(va_list args);
int printf_int(va_list args);

#endif

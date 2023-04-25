#ifndef CONVERT_H
#define CONVERT_H

#include <stdarg.h>
typedef struct convert_match
{
	char *specifier;
	int (*f)(va_list);
} convert_match;

extern convert_match m[];
#endif

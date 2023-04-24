#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

int _printf(const char *format, ...);
int printf_37(void);
int printf_exclusive_string(va_list val);
int printf_char(va_list val);
int _putchar(char c);
int printf_HEX_aux(unsigned int num);
#endif

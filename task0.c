#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - outputs according to a string format.
 * @format: a character string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	if (*format == '%')
	{
		putchar('%');
	}
	
	va_end(args);
	return (0);
}

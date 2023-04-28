#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: 0
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list params;

	va_start(params, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			putchar('%');
			count++;
		}
	}
	return (count);
}

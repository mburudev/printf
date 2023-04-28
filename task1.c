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
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == 'd')
		{
			int num = va_arg(args, int);

			count += printf("%d", num);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'i')
		{
			int num = va_arg(args, int);

			count += printf("%i", num);
			format += 2;
		}
		else
		{
			putchar(*format);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}

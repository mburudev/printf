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
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);

				putchar(c);
				count++;
			} else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
			} else if (*format == '%')
			{
				putchar('%');
				count++;
			} else
			{}
		} else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

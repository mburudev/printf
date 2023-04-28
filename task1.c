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

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'd' || *format == 'i')
			{
				int value = va_arg(args, int);

				count += print_integer(value);
			}
			else
			{
				count += putchar('%');
				count += putchar(*format);
			}
		}
		else
		{
			count += putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}

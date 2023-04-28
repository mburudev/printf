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
	int i;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++; /* skip the '%' */
			if (*format == 'b')
			{
				unsigned int value = va_arg(args, unsigned int);
				/* convert the value to binary and print it */
				for (i = 31; i >= 0; i--)
				{
					putchar((value & (1 << i)) ? '1' : '0');
					count++;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);

	return (count);
}

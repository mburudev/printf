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
	va_list arg;
	int length = 0;

	va_start(arg, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'u':
				length += printf("%u", va_arg(arg, unsigned int));
				break;
			case 'o':
				length += printf("%o", va_arg(arg, unsigned int));
				break;
			case 'x':
				length += printf("%x", va_arg(arg, unsigned int));
				break;
			case 'X':
				length += printf("%X", va_arg(arg, unsigned int));
				break;
			default:
				length += printf("%%%c", *format);
				break;
			}
		}
		else
		{
			putchar(*format);
			length++;
		}
		format++;
	}
	va_end(arg);
	return (length);
}

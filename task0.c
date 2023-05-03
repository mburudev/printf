#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	int d;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				d = va_arg(args, int);

				printf("%d", d);
				count++;
			} else if (*format == '%')
			{
				putchar('%');
				count++;
			} else
			{
				putchar('?');
				count++;
			}
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

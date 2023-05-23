#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: unsigned int in binary.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				count += printf("%%");
				format += 2;
				continue;
			}
		}
		count += printf("%c", *format);
		format++;
	}
	va_end(args);
	return (count);
}

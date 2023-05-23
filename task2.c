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
	while (*format)
	{
		if (*format == '%')
		{
			switch (*++format)
			{
			case 'u':
				count += printf("%u", va_arg(args, unsigned int));
				break;
			case 'o':
				count += printf("%o", va_arg(args, unsigned int));
				break;
			case 'x':
				count += printf("%x", va_arg(args, unsigned int));
				break;
			case 'X':
				count += printf("%X", va_arg(args, unsigned int));
				break;
			default:
				count += putchar(*format);
				break;
			}
		} else
		{
			count += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

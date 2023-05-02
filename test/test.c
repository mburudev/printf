
#include <stdarg.h>



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
			if (*format == 's')
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

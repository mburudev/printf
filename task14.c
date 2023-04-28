#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <ctype.h>
#include <string.h>

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int i;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'R')
			{
				char *str = va_arg(args, char *);
				for (i = 0; str[i]; i++)
				{
					if (isalpha(str[i]))
					{
						if (islower(str[i]))
							putchar((str[i] - 'a' + 13) % 26 + 'a');
						else
							putchar((str[i] - 'A' + 13) % 26 + 'A');
						count++;
					}
					else
					{
						putchar(str[i]);
						count++;
					}
				}
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
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

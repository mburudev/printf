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
	int i;
	int output;
	int binary[32];

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
					for (i = 0; value > 0; i++) {
     					   binary[i] = value % 2;
    				    value = value / 2;
    						}
					    for (i = i - 1; i >= 0; i--) {
        output = putchar(binary[i] + '0');
    }
					count++;
		
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

	return (output);
}

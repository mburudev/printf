#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: unsigned int in binary.
 */

int _printf(const char *format, ...) {
	int count, i, output;
	int binary[32];
	char ch;
    va_list args;
    va_start(args, format);

    count = 0;
   

    while ((ch = *format++) != '\0') {
        if (ch == '%') {
            ch = *format++;
            switch (ch) {
                case 'd':
                case 'i':
                    count += printf("%d", va_arg(args, int));
                    break;
                case 'b':
                    {
                        unsigned int value = va_arg(args, unsigned int);

				for (i = 0; value > 0; i++)
				{
					binary[i] = value % 2;
					value = value / 2;
				}
				for (i = i - 1; i >= 0; i--)
				{
					output = putchar(binary[i] + '0');
				}
				count++;
                    }
                    break;
                default:
                    count += printf("%%%c", ch);
                    break;
            }
        } else {
            putchar(ch);
            count++;
        }
    }

    va_end(args);

    return output;
}

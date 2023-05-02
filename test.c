#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: the number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
    if (format == NULL) {
        return -1;
    }

    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }

                case 's': {
                    char *s = va_arg(args, char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }

                case '%': {
                    putchar('%');
                    count++;
                    break;
                }

                default: {
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
                }
            }
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

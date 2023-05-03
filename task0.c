#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: 0
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;

    while ((c = *(format++)) != '\0') {
        if (c != '%') {
            putchar(c);
            count++;
        } else {
            c = *(format++);
            if (c == 'd' || c == 'i') {
                int value = va_arg(args, int);
                printf("%d", value);
                count++;
            }
        }
    }

    va_end(args);

    return count;
}

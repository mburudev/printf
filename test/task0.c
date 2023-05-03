#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: 0
 */
int _printf(const char *format, ...) {
	char  ch;
	int count;
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

    return count;
}

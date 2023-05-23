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
    char buffer[1024]; 

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            if (*(format + 1) == '%')
            {
                count += sprintf(buffer, "%%");
                printf("%s", buffer);
                format += 2;
                continue;
            }
            switch (*++format)
            {
                case 'c':
                    count += sprintf(buffer, "%c", va_arg(args, int));
                    printf("%s", buffer);
                    break;
                case 's':
                    count += sprintf(buffer, "%s", va_arg(args, char*));
                    printf("%s", buffer);
                    break;
                default:
                    count += sprintf(buffer, "%%%c", *format);
                    printf("%s", buffer);
                    break;
            }
        } else
        {
            count += sprintf(buffer, "%c", *format);
            printf("%s", buffer);
        }
        format++;
    }

    va_end(args);
    return count;
}

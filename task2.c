#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a string format.
 * @format: a character string
 * Return: unsigned int in binary.
 */

int _printf(const char *format, ...) {
  va_list args;
  int count = 0;

  va_start(args, format);
  while (*format != '\0') {
    if (*format == '%') {
      switch (*++format) {
        case 'c':
          count += printf("%c", va_arg(args, int));
          break;
        case 's':
          count += printf("%s", va_arg(args, char*));
          break;
        default:
          count += printf("%%%c", *format);
          break;
      }
    } else {
      count += printf("%c", *format);
    }
    format++;
  }

  va_end(args);

  return count;
}

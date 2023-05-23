#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char* decimalToBinary(unsigned int num) {
	int i;
    int bits = sizeof(num) * 8;
    char* binary = malloc(bits + 1); 
    if (binary == NULL) {
        return NULL;
    }

    binary[bits] = '\0'; 
    for (i = bits - 1; i >= 0; i--) {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }

    return binary;
}

int _printf(const char* format, ...) {
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
                case 'b': {
                    unsigned int num = va_arg(args, unsigned int);
                    char* binary = decimalToBinary(num);
                    if (binary != NULL) {
                        count += printf("%s", binary);
                        free(binary);
                    } else {
                        count += printf("[Memory Allocation Error]");
                    }
                    break;
                }
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

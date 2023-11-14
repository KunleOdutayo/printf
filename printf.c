#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...){
    int n = 0;
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format != '%') {
            write(1, format, 1);
            n++;
            format++;
            continue;
        }
        format++;
        switch (*format) {
            case '%': {
                write(1, format, 1);
                n++;
                break;
            }
            case 'c': {
                char c = va_arg(args, int);
                write(1, &c, 1);
                n++;
                break;
            }
            case 's': {
                char* s = va_arg(args, char*) ;
                while (*s) {
                    write(1, s++, 1);
                    n++;
                }
                break;
            }
            case 'd':
            case 'i': {
                int num = va_arg(args, int);
                char buffer[20];
                int i = 0;
                if (num < 0) {
                    char sign = '-';
                    write(1, &sign, 1);
                    n++;
                    num = -num;
                }
                if (num == 0) {
                    buffer[i++] = '0';
                }
                while (num > 0) {
                    buffer[i++] = '0' + (num % 10);
                    num /= 10;
                }
                while (i--) {
                    write(1, &buffer[i], 1);
                    n++;
                }
                break;
            }

            default: {
                write(1, format, 1);
                n++;
                break;
            }
        }
        format++;
    }

    va_end(args);


    return n;
}

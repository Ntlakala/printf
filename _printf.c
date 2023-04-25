#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list list;
    int i, printed = 0;
    char buffer[1024];

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            switch (format[++i]) {
                case 's':
                    printed += printf("%s", va_arg(list, char *));
                    break;
                case 'd':
                    printed += printf("%d", va_arg(list, int));
                    break;
                case 'c':
                    printed += printf("%c", va_arg(list, int));
                    break;
                default:
                    printed += printf("%%%c", format[i]);
                    break;
            }
        } else {
            putchar(format[i]);
            printed++;
        }
    }

    va_end(list);

    return printed;
}


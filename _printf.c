#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
int _puts(char *str);
int print_number(int n);

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char buffer[12]; /* buffer to hold integer as string */

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);

			switch (*format)
			{
				case 'c':
					buffer[0] = va_arg(args, int);
					printed_chars += write(1, buffer, 1);
					break;
				case 's':
					buffer[0] = '\0';
					buffer[0] = *va_arg(args, char *);
					printed_chars += write(1, buffer, 1);
					break;
				case '%':
					buffer[0] = '%';
					printed_chars += write(1, buffer, 1);
					break;
				case 'd':
				case 'i':
					sprintf(buffer, "%d", va_arg(args, int));
					printed_chars += write(1, buffer, strlen(buffer));
					break;
				default:
					buffer[0] = '%';
					buffer[1] = *format;
					printed_chars += write(1, buffer, 2);
					break;
			}
		}
		else
		{
			buffer[0] = *format;
			printed_chars += write(1, buffer, 1);
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

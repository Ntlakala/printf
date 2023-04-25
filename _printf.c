#include "main.h"
#include <unistd.h> /* for write */
#include <stdio.h> /* for NULL */
#include <stdlib.h> /* for va_start, va_arg, va_end */

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char buffer[2] = {'\0', '\0'};

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
/** 
* print_number - prints an integer 
* @n: integer to be printed *
* Return: number of digits printed 

*/

int print_number(int n) { unsigned int m; int digits = 0; 
if (n < 0) { _putchar('-'); m = -n; 
}
else m = n; 
if (m / 10) digits += print_number(m / 10); 
_putchar(m % 10 + '0'); 
digits++; return (digits); 
}

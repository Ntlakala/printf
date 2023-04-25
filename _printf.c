#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed (excluding null byte)
 */

int _putchar(char c);
int _puts(char *str);
int print_number(int n);

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char *str;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					printed_chars += _puts(str);
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				case 'd':
				case 'i':
					printed_chars += print_number(va_arg(args, int));
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
			printed_chars += _putchar(*format);
		format++;
	}
	va_end(args);
	return (printed_chars);
}

/**
 * print_number - prints an integer
 * @n: integer to be printed
 *
 * Return: number of digits printed
 */
int print_number(int n)
{
	unsigned int m;
	int digits = 0;

	if (n < 0)
	{
		_putchar('-');
		m = -n;
	}
	else
		m = n;

	if (m / 10)
		digits += print_number(m / 10);

	_putchar(m % 10 + '0');
	digits++;

	return (digits);
}


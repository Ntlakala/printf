#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>

/* function prototypes */
int _printf(const char *format, ...);
int handle_print(const char format, int *i, va_list list, char *buffer, int *buff_ind);
int print_char(char c, char *buffer, int *buff_ind);
int print_string(char *str, char *buffer, int *buff_ind);
int print_number(int n, char *buffer, int *buff_ind);

#endif /* _PRINTF_H_ */


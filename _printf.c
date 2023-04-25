/*

main.h - header file to define functions and constants
*/
void print_buffer(char buffer[], int *buff_ind); // Function prototype

/**

_printf - Printf function

@format: format.

Return: Printed chars.
*/
int _printf(const char format, ...)
{
/ Declare and initialize variables */
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];

/* Check if format is NULL and return -1 if it is */
if (format == NULL)
return (-1);

/* Start variable argument list */
va_start(list, format);

/* Loop through the format string /
for (i = 0; format && format[i] != '\0'; i++)
{
/ If the current character is not a %, add it to the buffer and increment buff_ind /
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/ Alternative: write(1, &format[i], 1); /
printed_chars++;
}
/ If the current character is a %, parse the format specifier and handle the argument accordingly /
else
{
/ Flush the buffer before parsing the format specifier /
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
/ Return -1 if handle_print returns -1 */
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

/* Flush the buffer one last time before returning */
print_buffer(buffer, &buff_ind);

/* End variable argument list */
va_end(list);

/* Return the number of printed characters */
return (printed_chars);
}

/**

print_buffer - Prints the contents of the buffer if it exist

@buffer: Array of chars

@buff_ind: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int buff_ind)
{
/ If the buffer has any contents, print them to stdout and reset the buffer index */
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}






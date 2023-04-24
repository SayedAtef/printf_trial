#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Pointer to the current index of fmt string.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 *
 * Return: Number of characters printed, or -1 on failure.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[])
{
    int i, unknown_len = 0, printed_chars = -1;
    fmt_t fmt_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent}, {'i', print_int}, {'d', print_int}, {'\0', NULL}};
    for (i = 0; fmt_types[i].fmt != '\0'; i++)
        if (fmt[*ind] == fmt_types[i].fmt)
            return (fmt_types[i].fn(list, buffer));

    if (fmt_types[i].fmt == '\0')
    {
        if (fmt[*ind] == '\0')
            return (-1);
        unknown_len += write(1, "%%", 1);
        if (fmt[*ind - 1] == ' ')
            unknown_len += write(1, " ", 1);
        else if (*ind > 0)
        {
            --(*ind);
            while (fmt[*ind] != ' ' && fmt[*ind] != '%')
                --(*ind);
            if (fmt[*ind] == ' ')
                --(*ind);
            return (1);
        }
        unknown_len += write(1, &fmt[*ind], 1);
        return (unknown_len);
    }
    return (printed_chars);
}

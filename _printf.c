#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list list;

    if (format == NULL)
        return (-1);

    va_start(list, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            printed_chars++;
        }
        else
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(list, int);
                putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(list, char *);
                if (s == NULL)
                    s = "(null)";
                while (*s)
                {
                    putchar(*s);
                    s++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                printed_chars++;
            }
        }
        format++;
    }

    va_end(list);

    return (printed_chars);
}

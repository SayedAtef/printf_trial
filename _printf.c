#include "main.h"

void printBuffer(char buffer[], int *buffIndex);

/**
 * _printf - custom implementaion of printf function
 * @format: format pointer.
 * Return: chars that has been printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, printed = 0, printedChars = 0;
	int flags, width, precision, size, buffIndex = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buffIndex++] = format[i];
			if (buffIndex == BUFF_SIZE)
				printBuffer(buffer, &buffIndex);
			printedChars++;
		}
		else
		{
			printBuffer(buffer, &buffIndex);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printedChars += printed;
		}
		i++;
	}

	printBuffer(buffer, &buffIndex);

	va_end(list);

	return (printedChars);
}

/**
 * printBuffer - Prints the buffer contents if there is any
 * @buffer: Array of chars to be printed
 * @buffIndex: Index at which to add next char, represents the length.
 */
void printBuffer(char buffer[], int *buffIndex)
{
	if (*buffIndex > 0)
		write(1, &buffer[0], *buffIndex);

	*buffIndex = 0;
}

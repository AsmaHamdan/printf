#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printformated function
 * @format: format is an argument in _printf function.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int co, pri = 0, pri2 = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char store[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);
	for (co = 0; format && format[co] != '\0'; co++)
	{
		if (format[co] != '%')
		{
			store[buff_ind++] = format[co];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(store, &buff_ind);
			}
			pri2++;
		}
		else
		{
			print_buffer(store, &buff_ind);
			flags = get_flags(format, &co);
			width = get_width(format, &co, list);
			precision = get_precision(format, &co, list);
			size = get_size(format, &co);
			++co;
			pri = handle_print(format, &co, list, store, flags, width, precision, size);
			if (pri == -1)
			{
				return (-1);
			}
			pri2 += pri;
		}
	}
	print_buffer(store, &buff_ind);
	va_end(list);
	return (pri2);
}
/**
 * print_buffer - dis function will prin the content
 * of the buff
 * @buff_ind: buffer the pres the length.
 * @buffer: the arr of character
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
		/*write is a function and it is forme is write(i, &var,j)*/
	}
	*buff_ind = 0;
}

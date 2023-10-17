#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width. 
 */
int get_width(const char *format, int *i, va_list list)
{
	int wid_count;
	int WID = 0;

	for (wid_count = *i + 1; format[wid_count] != '\0'; wid_count++)
	{
		if (is_digit(format[wid_count]))
		{
			WID = WID * 10;
			WID = WID + format[wid_count] - '0';
		}
		else if (format[wid_count] == '*')
		{
			wid_count++;
			WID = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = wid_count - 1;
	return (WID);
}

#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int PreS = -1;
int wid_cou = *i + 1;

	if (format[wid_cou] != '.')
	{
		return (PreS);
	}
	PreS = 0;
	for (wid_cou += 1; format[wid_cou] != '\0'; wid_cou++)
	{
	if (format[wid_cou] == '*')
	{
		wid_cou++;
		PreS = va_arg(list, int);
		break;
	}
	else if (is_digit(format[wid_cou]))
	{
		PreS = PreS * 10;
		PreS = PreS + format[wid_cou] - '0';
	}
		else
		break; }
	*i = wid_cou - 1;
	return (PreS);
}

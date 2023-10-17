#include "main.h"

/**
 * get_size - Calculates the siz
 * @format: Forma strin
 * @i: counter of argument
 * Return: Size
 */
int get_size(const char *format, int *i)
{
	int SAZ_counter = *i + 1;
	int Si = 0;

	if (format[SAZ_counter] == 'l')
	{
		Si = S_LONG;
	}
	else if (format[SAZ_counter] == 'h')
	{
		Si = S_SHORT;
	}
	if (Si == 0)
	{
		*i = SAZ_counter - 1;
	}
	else
	{
		*i = SAZ_counter;
	}
	return (Si);
}

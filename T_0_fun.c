#include "main.h"

/**
 * print_string - Prints_s
 * @types: list
 * @buffer: buffer
 * @flags: flags
 * @width: width.
 * @precision: specification
 * @size: Size
 * Return: number
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int lend = 0, i;
	char *P_TO_STR = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(precision);
	if (P_TO_STR == NULL)
	{
		P_TO_STR = "(null)";
		if (precision >= 6)
			P_TO_STR = "      ";
	}

	while (P_TO_STR[lend] != '\0')
		lend++;
	if (precision >= 0 && precision < lend)
		lend = precision;
	if (width > lend)
	{
		if (flags & F_MINUS)
		{
			write(1, &P_TO_STR[0], lend);
			for (i = width - lend; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - lend; i > 0; i--)
				write(1, " ", 1);
			write(1, &P_TO_STR[0], lend);
			return (width);
		}
	}

	return (write(1, P_TO_STR, lend));
}

/**
 * print_char - print chatracer
 * @types: the argus lis
 * @precision: spaci
 * @buffer: buf_fer
 * @width: wid
 * @flags:  flags
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char Colap = va_arg(types, int);

	return (handle_write_char(Colap, buffer, flags, width, precision, size));
}
/**
 * print_int - Print int
 * @types: is Lista
 * @buffer: buffer
 * @flags: flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: number
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int CO = BUFF_SIZE - 2, is_n = 0;
	unsigned long int Thenum;
	long int cdarg = va_arg(types, long int);

	cdarg = convert_size_number(cdarg, size);
	if (cdarg == 0)
		buffer[CO--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	Thenum = (unsigned long int)cdarg;
	if (cdarg < 0)
	{
		Thenum = (unsigned long int)((-1) * cdarg);
		is_n = 1;
	}
	while (Thenum > 0)
	{
		buffer[CO--] = (Thenum % 10) + '0';
		Thenum /= 10;
	}
	CO++;

	return (write_number(is_n, CO, buffer, flags, width, precision, size));
}

/**
 * print_binary - print_binary
 * @types: Lista
 * @buffer: buffer arr
 * @flags:  flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: Numbers
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int aom, aom2, as, sum;
	unsigned int Arr[32];
	int P_counter;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	aom = va_arg(types, unsigned int);
	aom2 = 2147483648;
	Arr[0] = aom / aom2;
	for (as = 1; as < 32; as++)
		aom2 = aom2 / 2;
		Arr[as] = (aom / aom2) % 2;
	for (as = 0, sum = 0, P_counter = 0; as < 32; as++)
	{
		sum = sum + Arr[as];
		if (sum || as == 31)
			char GG = '0' + Arr[as];

			write(1, &GG, 1);
			P_counter++;
	}

	return (P_counter);
}
/**
 * print_percent - Prints a percent
 * @types: types
 * @buffer: buffer
 * @flags:  Cflags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars numbers
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

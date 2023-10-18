#include "main.h"

/**
 * print_unsigned - unsigned number
 * @types: List
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - 2;
	unsigned long int len2 = va_arg(types, unsigned long int);

	len2 = convert_size_unsgnd(len2, size);

	if (len2 == 0)
		buffer[len--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (len2 > 0)
	{
		buffer[len--] = (len2 % 10) + '0';
		len2 /= 10;
	}

	len++;

	return (write_unsgnd(0, len, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista
 * @buffer: Buffer
 * @flags:  Cflags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int len = BUFF_SIZE - 2;
	unsigned long int len2 = va_arg(types, unsigned long int);
	unsigned long int len3 = len2;

	UNUSED(width);

	len2 = convert_size_unsgnd(len2, size);

	if (len2 == 0)
		buffer[len--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (len2 > 0)
	{
		buffer[len--] = (len2 % 8) + '0';
		len2 /= 8;
	}

	if (flags & F_HASH && len3 != 0)
		buffer[len--] = '0';

	len++;

	return (write_unsgnd(0, len, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 * Return: Number printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
	flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - a function Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 *
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int ji = BUFF_SIZE - 2;
	unsigned long int number1;
	unsigned long int Inumber;

	number1 = va_arg(types, unsigned long int);
	Inumber = number1;
	UNUSED(width);
	number1 = convert_size_unsgnd(number1, size);

	if (number1 == 0)
		buffer[ji--] = '0';
		buffer[BUFF_SIZE - 1] = '\0';
	while (number1 > 0)
	{
		buffer[ji--] = map_to[number1 % 16];
		number1 /= 16;
	}
	if (flags & F_HASH && Inumber != 0)
	{
		buffer[ji--] = flag_ch;
		buffer[ji--] = '0';
	}
	ji++;

	return (write_unsgnd(0, ji, buffer, flags, width, precision, size));
}

#include "main.h"

/**
 * append_hexa_code - appen hexs code
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char Value[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i] = Value[ascii_code % 16];
	buffer[i++] = Value[ascii_code / 16];
	return (3);
}

/**
 * convert_size_unsgnd -convert size unsgned function
 * @num: numbe
 * @size: Number indicating the
 * type to be casted
 *
 * Return: return cast
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}

/**
 * is_digit - dis function will test
 * the number
 * is digit or not
 * @c: Char/character
 * Return: return 1 or 0
 */
int is_digit(char c)
{
	if (c <= '9' && c >= '0')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - convert_size_size
 * @num: is a number
 * @size: Nsize
 * Return: cas
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}

	return ((int)num);
}


/**
 * is_printable - dis funtion will test case is
 * printable or not
 * @c: Char/character
 *
 * Return: return 0 or 1
 */
int is_printable(char c)
{
	if (c < 127 && c >= 32)
	{
		return (1);
	}

	return (0);
}

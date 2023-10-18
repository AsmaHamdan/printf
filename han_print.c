#include "main.h"

/**
 * print_pointer - Print ptr value
 * @types: lis the arguems
 * @buffer: buffer handle
 * @width: width
 * @flags: flags
 * @size: Size
 * @precision: Precision
 * Return: Number of chars
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char FRX = 0, REX = ' ';
	int ind = BUFF_SIZE - 2;
	int  len = 2;
	int padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		REX = '0';
	if (flags & F_PLUS)
		FRX = '+', len++;
	else if (flags & F_SPACE)
		FRX = ' ', len++;

	ind++;
	return (write(1, &buffer[len], BUFF_SIZE - len - 1));/*len or padd_start?*/
	return (write_pointer(buffer, ind, len,
		width, flags, REX, FRX, padd_start));
}

/**
 * print_non_printable - Prints asciis code
 * @flags:  Calculater
 * @precision: Precision specification
 * @buffer: Buffer
 * @types: list.
 * @width: get width
 * @size: Size
 * Return: printed Number
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int INT = 0, stepp = 0;
	char *Stri_p = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);

	if (Stri_p == NULL)
		return (write(1, "(null)", 6));

	while (Stri_p[INT] != '\0')
	{
		if (is_printable(Stri_p[INT]))
			buffer[INT + stepp] = Stri_p[INT];
		else
			stepp = stepp + append_hexa_code(Stri_p[INT], buffer, INT + stepp);

		INT++;
	}

	buffer[INT + stepp] = '\0';

	return (write(1, buffer, INT + stepp));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lista
 * @flags:  Calculates active flags
 * @buffer: Buffer
 * @precision: Precision
 * @size: Size
 * @width: get
 * Return: Number
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *StR;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	StR = va_arg(types, char *);

	if (StR == NULL)
	{
		UNUSED(precision);

		StR = ")Null(";
	}
	for (i = 0; StR[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char Mu = StR[i];

		write(1, &Mu, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - dis functhion will Print a string in rot13.
 * @types: Lista of arguments
 * @precision: Precision
 * @flags:  Calculates
 * @width: get
 * @size: Size
 * @buffer: print
 *
 * Return: Numbers
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char val;
	char *sStrtr;
	unsigned int f, j;
	int Cou_nter = 0;
	char Out_put[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char In_put[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	sStrtr = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (sStrtr == NULL)
		sStrtr = "(AHYY)";
	for (f = 0; sStrtr[f]; f++)
	{
		for (j = 0; In_put[j]; j++)
		{
			if (In_put[j] == sStrtr[f])
			{
				val = Out_put[j];
				write(1, &val, 1);
				Cou_nter++;
				break;
			}
		}
		if (!In_put[j])
		{
			val = sStrtr[f];
			write(1, &val, 1);
			Cou_nter++;
		}
	}
	return (Cou_nter);
}

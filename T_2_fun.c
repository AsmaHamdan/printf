#include "main.h"

/**
 * print_non_printable - print_non_printable
 * @buffer: Buffer array to handle print
 * @types: Lista.
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: size.
 * Return: NUM chars printed
 */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char *str_ing = va_arg(types, char *);
	int IN_num = 0;
	int  NoN = 0;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str_ing == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str_ing[IN_num] != '\0')
	{
		if (is_printable(str_ing[IN_num]))
		{
			buffer[IN_num + NoN] = str_ing[IN_num];
		}
		else
		{
			NoN += append_hexa_code(str_ing[IN_num], buffer, IN_num + NoN);
		}
		IN_num++;
	}

	buffer[IN_num + NoN] = '\0';
	return (write(1, buffer, IN_num + NoN));
}

/**
 * print_reverse - print_reverse.
 * @buffer: Buffer print
 * @types: Lista.
 * @flags: flags
 * @precision: Precision
 * @size: size.
 * @width: width
 * Return: NUM chars printed
 */

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int C_ounter = 0;
	int INDEX;
	char *STr_ing;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	STr_ing = va_arg(types, char *);
	if (STr_ing == NULL)
	{
		UNUSED(precision);
		STr_ing = ")Null(";
	}
	for (INDEX = 0; STr_ing[INDEX]; INDEX++)
	{
		;
	}
	for (INDEX = INDEX - 1; INDEX >= 0; INDEX--)
	{
		char STO = STr_ing[INDEX];

		write(1, &STO, 1);
		C_ounter++;
	}
	return (C_ounter);
}

/**
* print_pointer - print_pointer.
* @buffer: Buffer array to handle print
* @types: Lista.
* @flags: flags
* @precision: Precision
* @width: width
* @size: size.
* Return: NUM chars printed
*/
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char P_Prin[] = "0123456789abcdef";
	char CC = 0, PADDINING = ' ';
	int BUf_i = BUFF_SIZE - 2;
	int length = 2;
	int padd_start = 1;
	unsigned long Number_of_add;
	void *PT_ADRE = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (PT_ADRE == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	Number_of_add = (unsigned long)PT_ADRE;

	while (Number_of_add > 0)
	{
		buffer[BUf_i--] = P_Prin[Number_of_add % 16];
		Number_of_add /= 16;
		length++;
	}
	
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	PADDINING = '0';

	if (flags & F_PLUS)
		CC = '+', length++;
	else if (flags & F_SPACE)
		CC = ' ', length++;

	BUf_i++;

	return (write_pointer(buffer, BUf_i, length,
	width, flags, PADDINING, CC, padd_start));
}

/**
* print_pointer - print_pointer.
* @buffer: Buffer array to handle print
* @types: Lista.
* @flags: flags
* @precision: Precision
* @size: size.
* @width: width
* Return: NUM chars printed
*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char Input_rot[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char Output_rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char cha_r;
	char *STrin_n;
	int rot = 0;
	unsigned int First_l, Second_l;

	STrin_n = va_arg(types, char *);
	UNUSED(size);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(buffer);

	if (STrin_n == NULL)
	{
		STrin_n = "(AHYY)";
	}
	for (First_l = 0; STrin_n[First_l]; First_l++)
	{
		for (Second_l = 0; Input_rot[Second_l]; Second_l++)
		{
			if (Input_rot[Second_l] == STrin_n[First_l])
			{
				cha_r = Output_rot[Second_l];
				write(1, &cha_r, 1);
				rot++;
				break;
			}
		}
		if (!Input_rot[Second_l])
		{
			cha_r = STrin_n[First_l];
			write(1, &cha_r, 1);
			rot++;
		}
	}
	return (rot);
}

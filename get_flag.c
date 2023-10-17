#include "main.h"

/**
 * get_flags - dis is the Get_flag function
 * @format: formate, type char to print the string
 * @i: is a counter of parameters
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int F_counter, CCFM, Flg = 0;
	const char Fla_gs[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLS[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (CCFM = *i + 1; format[CCFM] != '\0'; CCFM++)
	{
	for (F_counter = 0; Fla_gs[F_counter] != '\0'; F_counter++)
	{
		if (format[CCFM] == Fla_gs[F_counter])
		{
			Flg |= FLS[F_counter];
				break;
		}
	}
	if (Fla_gs[F_counter] == 0)
	{
		break;
	}
	}
	*i = CCFM - 1;
	return (Flg);
}

/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_long
*/

#include "my_printf.h"

int my_print_decimal(unsigned long long value, char *buffer, int index,
int point)
{
    if (value > 9 || point > 0)
        my_print_decimal(value / 10, buffer, index - 1, point - 1);
    buffer[index] = value%10 + '0';
}

int my_print_signed_decimal(long long value, flags_t *flags)
{
    unsigned long long val = value < 0 ? -value : value;
    unsigned int length = my_nbrlen_base(val, 10, flags) +
    (value < 0 && !(flags->blank || flags->plus));
    char *buffer = my_calloc(length + 1, sizeof(char));

    if (value < 0)
        buffer[0] = '-';
    else if (flags->plus)
        buffer[0] = '+';
    else
        buffer[0] = ' ';
    my_print_decimal(val, buffer, length - 1, flags->point - 1);
    my_print_format_flag_number(flags, buffer, length);
    return (0);
}
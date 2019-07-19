/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_unsigned_integer
*/

#include "my_printf.h"

int my_print_udecimal(unsigned long long value, char *buffer,
int index, int point)
{
    if (value > 9 || point > 0)
        my_print_udecimal(value/10, buffer, index - 1, point - 1);
    buffer[index] = value%10 + '0';
    return (0);
}

int my_print_un_decimal(unsigned long long value, flags_t *flags)
{
    unsigned int length = my_nbrlen_base(value, 10, flags) -
    (flags->plus == 1);
    char *buffer = my_calloc(length + 1, sizeof(char));

    my_print_udecimal(value, buffer, length - 1, flags->point - 1);
    my_print_format_flag_number(flags, buffer, length);
    return (0);
}

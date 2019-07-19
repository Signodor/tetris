/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_hexadecimal
*/

#include "my_printf.h"

int my_print_hex(unsigned long long value, char *buffer, int index, int point)
{
    if (value > 15 || point > 0)
        my_print_hex(value / 16, buffer, index - 1, point - 1);
    if (value%16 > 9)
        buffer[index] = value%16 + 'a' - 10;
    else
        buffer[index] = value%16 + '0';
}

int my_print_format_hexadecimal(unsigned long long value, flags_t *flags)
{
    unsigned int length = my_nbrlen_base(value, 16, flags) +
    ((flags->hashtag == 1) * 2);
    char *buffer = my_calloc(length + 1, sizeof(char));

    if (flags->hashtag) {
        buffer[0] = '0';
        buffer[1] = 'x';
    }
    my_print_hex(value, buffer, length - 1, flags->point - 1);
    my_print_format_flag_number(flags, buffer, length);
    return (0);
}
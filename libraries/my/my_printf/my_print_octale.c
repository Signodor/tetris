/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_octale
*/

#include "my_printf.h"

int my_print_uoctale(unsigned long long value, char *buffer, int index,
int point)
{
    if (value > 7 || point > 0)
        my_print_uoctale(value/8, buffer, index - 1, point - 1);
    buffer[index] = value%8 + '0';
    return (0);
}

int my_print_format_octale(unsigned long long value, flags_t *flags)
{
    unsigned int length = my_nbrlen_base(value, 8, flags) +
    (flags->hashtag == 1);
    char *buffer = my_calloc(length + 1, sizeof(char));

    if (flags->hashtag)
        buffer[0] = '0';
    my_print_uoctale(value, buffer, length - 1, flags->point - 1);
    my_print_format_flag_number(flags, buffer, length);
    return (0);
}
/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_binary
*/

#include "my_printf.h"

int my_print_ubinary(unsigned long long value, char *buffer, int index,
int point)
{
    if (value > 1 || point > 0)
        my_print_ubinary(value / 2, buffer, index - 1, point - 1);
    buffer[index] = value%2 + '0';
}

int my_print_format_binary(unsigned long long value, flags_t *flags)
{
    unsigned int length = my_nbrlen_base(value, 2, flags) +
    ((flags->hashtag == 1) * 2);
    char *buffer = my_calloc(length + 1, sizeof(char));

    if (flags->hashtag) {
        buffer[0] = '0';
        buffer[1] = 'b';
    }
    my_print_ubinary(value, buffer, length - 1, flags->point - 1);
    my_print_format_flag_number(flags, buffer, length);
    return (0);
}
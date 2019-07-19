/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_flag_number
*/

#include "my_printf.h"

void my_put_flag(flags_t *flags, int length)
{
    for (int i = 0; i < flags->number - length; i++) {
        if (flags->minus || !flags->zero)
            my_putchar(' ');
        else
            my_putchar('0');
    }
}

void my_print_format_flag_number(flags_t *flags, char const *buffer,
int length)
{
    if (flags->minus) {
        my_putstr(buffer);
        if (flags->number > length)
            my_put_flag(flags, length);
    } else {
        if ((*buffer == '-' || *buffer == '+') && flags->zero) {
            my_putchar(*buffer);
            buffer++;
        }
        if (flags->number > length)
            my_put_flag(flags, length);
        my_putstr(buffer);
    }
}
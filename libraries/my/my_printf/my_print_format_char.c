/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_char
*/

#include "my_printf.h"

int my_print_format_char(va_list *list, flags_t *flags)
{
    char *buffer = my_calloc(2, sizeof(char));

    buffer[0] = va_arg(*list, int);
    my_print_format_flag_number(flags, buffer, 1);
    return (0);
}
/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_string
*/

#include "my_printf.h"

int my_print_format_string(va_list *list, flags_t *flags)
{
    const char *str = va_arg(*list, void *);

    flags->zero = 0;
    my_print_format_flag_number(flags, str, my_strlen(str));
    return (0);
}
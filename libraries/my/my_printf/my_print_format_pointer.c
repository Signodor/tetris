/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_pointer
*/

#include "my_printf.h"

int my_print_format_pointer(va_list *list, flags_t *flags)
{
    flags->hashtag = 1;
    my_print_hexadecimal(list, flags);
    return (0);
}
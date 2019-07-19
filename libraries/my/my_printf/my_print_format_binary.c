/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_binary
*/

#include "my_printf.h"

int my_print_hhbinary(va_list *list, flags_t *flags)
{
    return (my_print_format_binary((unsigned char)va_arg(*list, int),
    flags));
}

int my_print_hbinary(va_list *list, flags_t *flags)
{
    return (my_print_format_binary((unsigned short)va_arg(*list, int),
    flags));
}

int my_print_binary(va_list *list, flags_t *flags)
{
    return (my_print_format_binary((unsigned int)va_arg(*list, int),
    flags));
}

int my_print_lbinary(va_list *list, flags_t *flags)
{
    return (my_print_format_binary((unsigned long)va_arg(*list, long),
    flags));
}

int my_print_llbinary(va_list *list, flags_t *flags)
{
    return (my_print_format_binary(va_arg(*list, long long), flags));
}
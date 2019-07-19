/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_octale
*/

#include "my_printf.h"

int my_print_hhoctale(va_list *list, flags_t *flags)
{
    return (my_print_format_octale((unsigned char)va_arg(*list, int),
    flags));
}

int my_print_hoctale(va_list *list, flags_t *flags)
{
    return (my_print_format_octale((unsigned short)va_arg(*list, int),
    flags));
}

int my_print_octale(va_list *list, flags_t *flags)
{
    return (my_print_format_octale((unsigned int)va_arg(*list, int),
    flags));
}

int my_print_loctale(va_list *list, flags_t *flags)
{
    return (my_print_format_octale((unsigned long)va_arg(*list, long),
    flags));
}

int my_print_lloctale(va_list *list, flags_t *flags)
{
    return (my_print_format_octale(va_arg(*list, long long), flags));
}
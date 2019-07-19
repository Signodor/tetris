/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_hexadecimal
*/

#include "my_printf.h"

int my_print_hhhexadecimal(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal((unsigned char)va_arg(*list, int),
    flags));
}

int my_print_hhexadecimal(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal((unsigned short)va_arg(*list, int),
    flags));
}

int my_print_hexadecimal(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal((unsigned int)va_arg(*list, int),
    flags));
}

int my_print_lhexadecimal(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal((unsigned long)va_arg(*list, long),
    flags));
}

int my_print_llhexadecimal(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal(va_arg(*list, long long), flags));
}
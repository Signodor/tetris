/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_integer
*/

#include "my_printf.h"

int my_print_hhinteger(va_list *list, flags_t *flags)
{
    return (my_print_signed_decimal((char)va_arg(*list, int), flags));
}

int my_print_hinteger(va_list *list, flags_t *flags)
{
    return (my_print_signed_decimal((short)va_arg(*list, int), flags));
}

int my_print_integer(va_list *list, flags_t *flags)
{
    return (my_print_signed_decimal((int)va_arg(*list, int), flags));
}

int my_print_linteger(va_list *list, flags_t *flags)
{
    return (my_print_signed_decimal((long)va_arg(*list, long), flags));
}

int my_print_llinteger(va_list *list, flags_t *flags)
{
    return (my_print_signed_decimal(va_arg(*list, long long), flags));
}
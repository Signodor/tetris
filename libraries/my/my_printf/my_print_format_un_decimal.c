/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_un_decimal
*/

#include "my_printf.h"

int my_print_hhuinteger(va_list *list, flags_t *flags)
{
    return (my_print_un_decimal((unsigned char)va_arg(*list, int), flags));
}

int my_print_huinteger(va_list *list, flags_t *flags)
{
    return (my_print_un_decimal((unsigned short)va_arg(*list, int), flags));
}

int my_print_uinteger(va_list *list, flags_t *flags)
{
    return (my_print_un_decimal((unsigned int)va_arg(*list, int), flags));
}

int my_print_luinteger(va_list *list, flags_t *flags)
{
    return (my_print_un_decimal((unsigned long)va_arg(*list, long), flags));
}

int my_print_lluinteger(va_list *list, flags_t *flags)
{
    return (my_print_un_decimal(va_arg(*list, long long), flags));
}
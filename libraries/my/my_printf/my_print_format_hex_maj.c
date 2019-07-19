/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_hexadecimal
*/

#include "my_printf.h"

int my_print_hhhexadecimal_maj(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal_maj((unsigned char)va_arg(*list, int),
    flags));
}

int my_print_hhexadecimal_maj(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal_maj((unsigned short)va_arg(*list, int),
    flags));
}

int my_print_hexadecimal_maj(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal_maj((unsigned int)va_arg(*list, int),
    flags));
}

int my_print_lhexadecimal_maj(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal_maj((unsigned long)va_arg(*list, long),
    flags));
}

int my_print_llhexadecimal_maj(va_list *list, flags_t *flags)
{
    return (my_print_format_hexadecimal_maj(va_arg(*list, long long), flags));
}
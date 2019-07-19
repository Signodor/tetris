/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_float
*/

#include "my_printf.h"

int my_print_format_double(va_list *list, flags_t *flags)
{
    double value = va_arg(*list, double);
    int power = 1;
    int nbdigits = 2;
    long long int num;
    long long int decimal;

    for (int i = 0; i < nbdigits; i++)
        power *= 10;
    num = (long long int)(value);
    decimal = (long long int)((value - (double)num) * power);
    my_printf("%d.%d", num, decimal);
    return (0);
}
/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_nbrlen_base
*/

#include "my_printf.h"

unsigned int my_nbrlen_base(unsigned long long number, int base,
flags_t *flags)
{
    int blength = number < 0 || ((flags->plus || flags->blank) && base == 10);
    int length = 1;
    unsigned long long value = number < 0 ? -number : number;

    for (; value >= base; value /= base)
        length++;
    if (length >= flags->point)
        return (length + blength);
    return (flags->point + blength);
}
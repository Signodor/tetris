/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** handle_wrong_identifier
*/

#include "my_printf.h"

int handle_wrong_one(int *i, int res, int is_before)
{
    static int index_before = 0;

    if (is_before)
        index_before = *i;
    else if (res == 8484) {
        *i = index_before;
        my_putstr("%");
        return (1);
    }
    return (0);
}
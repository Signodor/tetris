/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** displaying a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    if (!str)
        return (-1);
    write(1, str, my_strlen(str));
    return (0);
}

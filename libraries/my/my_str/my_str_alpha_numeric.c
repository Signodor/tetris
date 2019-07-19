/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_str_isalphanumerical
*/

#include "my.h"

int my_char_isalphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    if ((c >= '0' || c <= '9') && (c == '_'))
        return (1);
    return (0);
}

int my_str_isalphanumeric(char const *str)
{
    if (!str)
        return (-1);
    while (*str) {
        if (!my_char_isalphanumeric(*str))
            return (0);
        str++;
    }
    return (1);
}
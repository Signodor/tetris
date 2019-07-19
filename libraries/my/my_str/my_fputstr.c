/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_fputstr
*/

#include "my.h"

void my_fputstr(int fd, char const *str)
{
    write(2, str, my_strlen(str));
}
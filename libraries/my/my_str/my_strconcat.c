/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_strconcat
*/

#include "my.h"

char *my_strconcat(char const *str_a, char const *str_b)
{
    char *ret = malloc(sizeof(char) *
    (my_strlen(str_a) + my_strlen(str_b) + 1));
    int index;
    int i;

    if (!ret)
        return (NULL);
    for (index = 0; str_a[index]; index++)
        ret[index] = str_a[index];
    for (i = 0; str_b[i]; i++)
        ret[index + i] = str_b[i];
    index += i;
    ret[index] = '\0';
    return (ret);
}

char *my_stricat(char const *str_a, char const *str_b, char const *str_c)
{
    char *ret = malloc(sizeof(char) *
    (my_strlen(str_a) + my_strlen(str_b) + my_strlen(str_c) + 1));
    int index;
    int i;

    if (!ret)
        return (NULL);
    for (index = 0; str_a[index]; index++)
        ret[index] = str_a[index];
    for (i = 0; str_b[i]; i++)
        ret[index + i] = str_b[i];
    index += i;
    for (i = 0; str_c[i]; i++)
        ret[index + i] = str_c[i];
    index += i;
    ret[index] = '\0';
    return (ret);
}
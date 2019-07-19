/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_str_replace
*/

#include "my.h"

static void filler(char *str, char *to_replace, char *replacing, char *ret)
{
    int index = 0;

    for (int i = 0; str[i]; i++) {
        if (!my_strncmp(str + i, to_replace, my_strlen(to_replace))) {
            my_strncpy(ret + index, replacing, my_strlen(replacing));
            i += my_strlen(to_replace) - 1;
            index += my_strlen(replacing) - 1;
        } else
            ret[index] = str[i];
        index++;
    }
}

char *my_str_replace(char *str, char *to_replace, char *replacing)
{
    int count = 0;
    char *ret;

    if (!str)
        return (replacing);
    if (!to_replace || !replacing)
        return (str);
    for (int i = 0; str[i]; i++)
        if (!my_strncmp(str + i, to_replace, my_strlen(to_replace)))
            count++;
    ret = my_calloc(sizeof(char), (my_strlen(str) - my_strlen(to_replace) *
    count + my_strlen(replacing) * count + 1));
    if (!ret)
        return (NULL);
    filler(str, to_replace, replacing, ret);
    return (ret);
}
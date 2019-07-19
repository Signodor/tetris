/*
** EPITECH PROJECT, 2019
** MUL_2018_my_defender
** File description:
** str
*/

#include "my.h"

char *my_strdup_to_ch(char *str, char end)
{
    char *ret;
    size_t size;
    int skip = 0;

    for (size = 0; str[size] && (str[size] != end || skip); size++)
        if (str[size] == '\"')
            skip = !skip;
    ret = malloc(sizeof(char) * (size + 1));
    if (!ret)
        return (NULL);
    for (size_t i = 0; i < size; i++)
        ret[i] = str[i];
    ret[size] = 0;
    return (ret);
}

char **str_to_tab(char *str, char c)
{
    char **res;
    size_t size = 1;

    if (!str)
        return (NULL);
    while ((*str) && (*str) == c)
        str++;
    for (int i = 0; str[i]; i++)
        size += (str[i] == c && str[i + 1] != c && str[i + 1] != '\0');
    if (!(res = malloc(sizeof(char *) * (size + 1))))
        return (NULL);
    for (int i = 0; i < size + 1; i++)
        res[i] = NULL;
    for (size_t i = 0; *str; i++) {
        res[i] = my_strdup_to_ch(str, c);
        str += my_strlen(res[i]);
        while ((*str) && (*str) == c)
            str++;
    }
    res[size] = NULL;
    return (res);
}
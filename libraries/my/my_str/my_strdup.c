/*
** EPITECH PROJECT, 2018
** my str_dup
** File description:
** string dupping
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *str = my_calloc(my_strlen(src) + 1, sizeof(char));

    if (str)
        my_strcpy(str, src);
    return (str);
}

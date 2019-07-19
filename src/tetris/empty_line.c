/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** empty_line
*/

#include <stdlib.h>

int is_full(char *str, int size)
{
    for (int i = 0; i < size; i++)
        if (!str[i])
            return (0);
    return (1);
}

char *str_cpy(char *src, int size)
{
    char *ret = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        ret[i] = src[i];
    return (ret);
}

char *fill_empty(int size)
{
    char *ret = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        ret[i] = 0;
    return (ret);
}

void empty_line(char **tab, int pos, int size)
{
    char *prev = fill_empty(size);
    char *tmp;

    for (int i = 0; i <= pos; i++) {
        tmp = str_cpy(tab[i], size);
        free(tab[i]);
        tab[i] = str_cpy(prev, size);
        free(prev);
        prev = str_cpy(tmp, size);
        free(tmp);
    }
    free(prev);
}
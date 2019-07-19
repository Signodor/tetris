/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tab
*/

#include "prototypes.h"

char **init_tab(int width, int height)
{
    char **back = malloc(sizeof(char *) * height);

    if (!back)
        return (0);
    for (int i = 0; i < height; i++) {
        if (!(back[i] = malloc(sizeof(char) * width)))
            return (NULL);
        for (int j = 0; j < width; j++)
            back[i][j] = 0;
    }
    return (back);
}

void free_str_to_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}
/*
** EPITECH PROJECT, 2018
** PSU_my_popup_2018
** File description:
** popup
*/

#include "prototypes.h"

int find_biggest(vector_t *vector)
{
    int len = 0;

    for (int i = 0; i < vector->max; i++)
        if (((tetriminos_t **)vector->elements)[i]->width > len)
            len = ((tetriminos_t **)vector->elements)[i]->width;
    return (len);
}

void popup(char *str, tetris_t *tetris)
{
    int row;
    int col;
    int height = 4 + tetris->map->height > 12 ? 4 + tetris->map->height : 12;
    int width = 26 + (tetris->map->width * 2) + 2 + !tetris->flag->no_next *
    (6 + find_biggest(tetris->tetriminos) + 2);

    getmaxyx(tetris->win, col, row);
    while (row < width || col < height) {
        clear();
        getmaxyx(tetris->win, col, row);
        mvprintw(col/2, (row - my_strlen(str)) / 2, str);
        refresh();
        usleep(1000);
    }
}
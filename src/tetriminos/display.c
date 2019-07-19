/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** display
*/

#include "prototypes.h"

void each(char **body, int i, int j)
{
    if (body[i][j] == '*')
        printw("* ");
}

void tetriminos_display(tetriminos_t *tetr, int x, int y)
{
    attron(COLOR_PAIR(tetr->color));
    for (int i = tetr->y < 0 ? tetr->y * -1 : 0; i < tetr->height; i++)
        for (int j = 0; j < tetr->width; j++) {
            move(y + i, x + j * 2);
            each(tetr->body, i, j);
        }
    attroff(COLOR_PAIR(tetr->color));
}
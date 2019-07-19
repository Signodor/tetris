/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** destructor
*/

#include "tetriminos.h"

void tetriminos_destroy(tetriminos_t *tetr)
{
    if (!tetr)
        return;
    for (int i = 0; i < tetr->height; i++)
        free(tetr->body[i]);
    free(tetr->name);
    free(tetr);
}
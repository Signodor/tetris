/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** constructor
*/

#include "prototypes.h"

tetris_t *tetris_create(flag_t *flags)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));

    if (!tetris)
        return (NULL);
    tetris->highscore = 0;
    tetris->level = flags->start_level;
    tetris->lines = 0;
    tetris->lines_tmp = 0;
    tetris->map = map_create(flags->width, flags->height);
    tetris->score = 0;
    tetris->flag = flags;
    tetris->end = 0;
    tetris->reserv = NULL;
    return (tetris);
}
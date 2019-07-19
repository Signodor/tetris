/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** update
*/

#include "prototypes.h"

void update_time(tetris_t *tetris)
{
    long sec = (long)((clock() - tetris->decalage)/ CLOCKS_PER_SEC);

    tetris->seconds = sec%60;
    tetris->minutes = sec/60;
    tetris->hours = sec/3600;
}

void update_tetris(tetris_t *tetris, flag_t *flags)
{
    update_time(tetris);
    if (!tetris->map->current) {
        tetris->map->current = tetriminos_spawn(tetris->map->next, flags);
        tetris->map->next = tetris->tetriminos->
        elements[rand()%tetris->tetriminos->max];
    }
    if (tetris->map->current)
        tetriminos_fall(tetris->map->current, tetris->map, tetris);
    for (int i = 0; i < tetris->map->height; i++) {
        if (is_full(tetris->map->body[i], tetris->map->width)) {
            tetris->lines++;
            tetris->lines_tmp++;
            tetris->score += 10 * tetris->level;
            empty_line(tetris->map->body, i, tetris->map->width);
        }
    }
    if (tetris->lines_tmp >= 10) {
        tetris->level++;
        tetris->lines_tmp -= 10;
    }
}
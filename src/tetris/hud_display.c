/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** hud_display
*/

#include "prototypes.h"

void display_reserv(tetris_t *tetris, map_t *map, tetriminos_t *tetr)
{
    if (!tetr)
        return;
    move(map_origin_y + 10, map_origin_x + map->width * 2 + 6);
    printw("/");
    for (int i = 0; i < tetr->width * 2; i++)
        printw("-");
    printw("\\");
    for (int i = 0; i < tetr->height; i++) {
        move(map_origin_y + 11 + i, map_origin_x + map->width * 2 + 6);
        printw("|");
        move(map_origin_y + 11 + i, map_origin_x +
        map->width * 2 + 6 + tetr->width * 2 + 1);
        printw("|");
    }
    move(map_origin_y + 11 + tetr->height, map_origin_x + map->width * 2 + 6);
    printw("\\");
    for (int i = 0; i < tetr->width * 2; i++)
        printw("-");
    printw("/");
    tetriminos_display(tetr,
    map_origin_x + map->width * 2 + 7, map_origin_y + 11);
}

void display_next(tetris_t *tetris, map_t *map, tetriminos_t *tetr)
{
    if (tetris->flag->no_next == true || !map->next)
        return;
    move(map_origin_y, map_origin_x + map->width * 2 + 6);
    printw("/");
    for (int i = 0; i < tetr->width * 2; i++)
        printw("-");
    printw("\\");
    for (int i = 0; i < tetr->height; i++) {
        move(map_origin_y + 1 + i, map_origin_x + map->width * 2 + 6);
        printw("|");
        move(map_origin_y + 1 + i, map_origin_x +
        map->width * 2 + 6 + tetr->width * 2 + 1);
        printw("|");
    }
    move(map_origin_y + 1 + tetr->height, map_origin_x + map->width * 2 + 6);
    printw("\\");
    for (int i = 0; i < tetr->width * 2; i++)
        printw("-");
    printw("/");
    tetriminos_display(map->next,
    map_origin_x + map->width * 2 + 7, map_origin_y + 1);
}

void hud_display(tetris_t *tetris)
{
    move(hud_origin_y, hud_origin_x);
    printw("/-----------------\\");
    for (int i = 0; i < 3; i++) {
        move(hud_origin_y + 1 + i * 3, hud_origin_x);
        printw("|                 |");
    }
    move(hud_origin_y + 2, hud_origin_x);
    printw("| Highscore %5d |", tetris->highscore);
    move(hud_origin_y + 3, hud_origin_x);
    printw("| Score %9d |", tetris->score);
    move(hud_origin_y + 5, hud_origin_x);
    printw("| Lines %9d |", tetris->lines);
    move(hud_origin_y + 6, hud_origin_x);
    printw("| Level %9d |", tetris->level);
    move(hud_origin_y + 8, hud_origin_x);
    printw("| Timer     %02d:%02d |", tetris->minutes, tetris->seconds);
    move(hud_origin_y + 9, hud_origin_x);
    printw("\\-----------------/");
    display_next(tetris, tetris->map, tetris->map->next);
    display_reserv(tetris, tetris->map, tetris->reserv);
}
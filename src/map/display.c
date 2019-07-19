/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** display
*/

#include "prototypes.h"

void display_floor(int width)
{
    printw(" +");
    for (int i = 0; i < width * 2; i++)
        printw("-");
    printw("+");
}

void display_tile(char c)
{
    if (!c) {
        printw("  ");
        return;
    }
    attron(COLOR_PAIR(c));
    printw("* ");
    attroff(COLOR_PAIR(c));
}

void map_display(map_t *map)
{
    move(map_origin_y, map_origin_x);
    display_floor(map->width);
    for (int i = 0; i < map->height; i++) {
        move(map_origin_y + i + 1, map_origin_x);
        printw(" |");
        for (int j = 0; j < map->width; j++)
            display_tile(map->body[i][j]);
        printw("|\n");
    }
    move(map_origin_y + map->height + 1, map_origin_x);
    display_floor(map->width);
    if (map->current) {
        tetriminos_display(map->current, map->current->x * 2 +
        map_origin_x + 2, map->current->y + map_origin_y + 1);
    }
}
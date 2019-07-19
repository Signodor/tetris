/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

typedef struct map map_t;

#include <stdlib.h>

#include "tetriminos.h"

static const int map_origin_x = 25;
static const int map_origin_y = 2;

struct map
{
    tetriminos_t *current;
    tetriminos_t *next;

    int width;
    int height;

    char **body;
};

map_t *map_create(int width, int height);

void map_display(map_t *map);
void display_floor(int width);

#endif /* !MAP_H_ */

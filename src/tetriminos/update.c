/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** update
*/

#include "prototypes.h"

static int check(tetriminos_t *tetr, map_t *map, int i, int j)
{
    int x = tetr->x + j;
    int y = tetr->y + i;

    if (tetr->body[i][j] == ' ')
        return (0);
    if (y + 1 >= map->height)
        return (1);
    if (map->body[y + 1][x] != 0)
        return (1);
    return (0);
}

int tetriminos_fall(tetriminos_t *tetr, map_t *map, tetris_t *tetris)
{
    int back = 0;

    for (int i = tetr->y < 0 ? tetr->y * -1 : 0; i < tetr->height; i++)
        for (int j = 0; j < tetr->width; j++)
            back += check(tetr, map, i, j);
    if (!back) {
        tetr->y++;
        return (0);
    }
    if (back && tetr->y < 0)
        tetris->end = 1;
    if (tetr->height >= map->height || tetr->width >= map->width)
        return (-1);
    for (int i = tetr->y < 0 ? tetr->y * -1 : 0; i < tetr->height; i++)
        for (int j = 0; j < tetr->width; j++)
            map->body[tetr->y + i][tetr->x + j] =
            tetr->body[i][j] == '*' ? tetr->color :
            map->body[tetr->y + i][tetr->x + j];
    map->current = NULL;
    return (1);
}

void tetriminos_rotate(tetriminos_t *tetr, map_t *map)
{
    int width = tetr->height;
    int height = tetr->width;
    char **body = init_tab(width, height);
    int back = 0;

    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            body[j][width - 1 - i] = tetr->body[i][j];
    if (tetr->x + width > map->width || tetr->y + height > map->height)
        return;
    for (int i = tetr->y < 0 ? tetr->y * -1 : 0; i < height; i++)
        for (int j = 0; j < width; j++)
            back += body[i][j] == '*' &&
            map->body[i + tetr->y][j + tetr->x] != 0;
    if (back)
        return;
    tetr->width = width;
    tetr->height = height;
    tetr->body = body;
}

void tetriminos_move(tetriminos_t *tetr, map_t *map, int sens)
{
    int x;
    int y;
    int back = 0;

    if (!tetr)
        return;
    x = tetr->x + sens;
    y = tetr->y;
    if (x < 0 || x + tetr->width > map->width)
        return;
    if (tetr->height >= map->height || tetr->width >= map->width)
        return;
    for (int i = tetr->y < 0 ? tetr->y * -1 : 0; i < tetr->height; i++)
        for (int j = 0; j < tetr->width; j++)
            back += map->body[y + i][x + j] != 0 && tetr->body[i][j] != ' ';
    if (back)
        return;
    tetr->x += sens;
}
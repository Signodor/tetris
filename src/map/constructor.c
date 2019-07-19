/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** constructor
*/

#include "map.h"

map_t *map_create(int width, int height)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return (NULL);
    map->width = width;
    map->height = height;
    map->current = NULL;
    map->next = NULL;
    if (!(map->body = malloc(sizeof(char *) * height)))
        return (NULL);
    for (int i = 0; i < height; i++) {
        if (!(map->body[i] = malloc(width)))
            return (NULL);
        for (int j = 0; j < width; j++)
            map->body[i][j] = 0;
    }
    return (map);
}
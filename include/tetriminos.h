/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetriminos
*/

#ifndef TETRIMINOS_H_
#define TETRIMINOS_H_

typedef struct tetriminos tetriminos_t;

#include "vector.h"
#include "map.h"
#include "flag.h"

struct tetriminos
{
    int *length;
    char **body;

    int color;

    char *name;

    int width;
    int height;

    int x;
    int y;
};

int tetrimino_load(tetriminos_t *tetrimino, char *filepath, flag_t *flags);

vector_t *load_tetriminos(flag_t *flags);

tetriminos_t *tetrimino_create(char *filepath, char *filename, flag_t *flags);

void tetriminos_display(tetriminos_t *tetriminos, int x, int y);
tetriminos_t *tetriminos_spawn(tetriminos_t *src, flag_t *flags);

void tetriminos_move(tetriminos_t *tetr, map_t *map, int sens);
void tetriminos_rotate(tetriminos_t *tetr, map_t *map);

void tetriminos_destroy(tetriminos_t *tetr);

int end_tetriminos(char const *filepath, char const *filename);

void delete_useless(vector_t *vec);
int tetriminos_sort(vector_t *tetriminos);

void display_line(char *str, int length);
#endif /* !TETRIMINOS_H_ */

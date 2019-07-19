/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include "map.h"
#include "flag.h"

static const int hud_origin_x = 2;
static const int hud_origin_y = 2;

typedef struct tetris
{
    int highscore;
    int score;

    int lines;
    int lines_tmp;
    int level;

    map_t *map;

    WINDOW *win;

    flag_t *flag;

    vector_t *tetriminos;

    long decalage;
    char hours;
    char minutes;
    char seconds;
    int end;
    
    tetriminos_t *reserv;
} tetris_t;

tetris_t *tetris_create(flag_t *flags);

void hud_display(tetris_t *tetris);

void update_tetris(tetris_t *tetris, flag_t *flags);
void empty_line(char **tab, int pos, int size);
int is_full(char *str, int size);
int tetriminos_fall(tetriminos_t *tetr, map_t *map, tetris_t *tetris);

#endif /* !TETRIS_H_ */

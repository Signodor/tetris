/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** sort
*/

#include "tetriminos.h"
#include "my.h"

int swap(vector_t *tetriminos, int i, int j)
{
    tetriminos_t *tetri = tetriminos->elements[i];
    tetriminos_t *tetrj = tetriminos->elements[j];
    char *lowi = my_strlowcase(my_strdup(tetri->name));
    char *lowj = my_strlowcase(my_strdup(tetrj->name));

    if (my_strcmp(lowi, lowj) > 0) {
        tetriminos->elements[i] = tetrj;
        tetriminos->elements[j] = tetri;
    }
    free(lowi);
    free(lowj);
    return (0);
}

int tetriminos_sort(vector_t *tetriminos)
{
    int back = 0;

    for (int i = 0; i < tetriminos->max && !back; i++) {
        for (int j = i + 1; j < tetriminos->max && !back; j++) {
            back = swap(tetriminos, i, j);
        }
    }
}
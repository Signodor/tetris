/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** event
*/

#include "prototypes.h"

char *get_event(tetris_t *tetris)
{
    char assault[3] = {0};
    char *buff = my_strdup("0");
    char *ex = tigetstr("kcub1");

    buff[0] = getch();
    if (buff[0] == -1)
        return (NULL);
    if (buff[0] == 27) {
        getch();
        assault[0] = ex[1];
        assault[1] = getch();
        buff = my_strconcat(buff, assault);
    }
    return (buff);
}

int command_event(char *key, tetris_t *tetris)
{
    if (!my_strcmp(key, tetris->flag->quit))
        tetris->end = 1;
    if (!my_strcmp(key, tetris->flag->pause))
        while (my_strcmp(get_event(tetris), tetris->flag->pause))
            usleep(10000);
    return (0);
}

void update_reserv(tetris_t *tetris)
{
    tetriminos_t *tmp = NULL;

    if (!tetris->map->current)
        return;
    if (tetris->reserv)
        tmp = tetris->reserv;
    tetris->reserv = tetris->map->current;
    tetris->reserv->y = 0;
    tetris->map->current = tmp;
    if (tetris->map->current)
        tetris->map->current->y = (tetris->map->current->height - 1) * -1;
}

int event(tetris_t *tetris)
{
    char *key;

    while ((key = get_event(tetris))) {
        if (!my_strcmp(key, tetris->flag->right))
            tetriminos_move(tetris->map->current, tetris->map, 1);
        if (!my_strcmp(key, tetris->flag->left))
            tetriminos_move(tetris->map->current, tetris->map, -1);
        if (!my_strcmp(key, tetris->flag->drop) && tetris->map->current)
            tetriminos_fall(tetris->map->current, tetris->map, tetris);
        if (!my_strcmp(key, tetris->flag->turn) && tetris->map->current)
            tetriminos_rotate(tetris->map->current, tetris->map);
        if (!my_strcmp(key, "o"))
            update_reserv(tetris);
        command_event(key, tetris);
        map_display(tetris->map);
        hud_display(tetris);
        refresh();
    }
    return (0);
}
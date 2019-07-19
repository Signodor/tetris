/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** play
*/

#include "prototypes.h"

int play(tetris_t *tetris, flag_t *flags)
{
    while (!tetris->end) {
        update_tetris(tetris, flags);
        clear();
        map_display(tetris->map);
        if (tetris->score >= tetris->highscore)
            tetris->highscore = tetris->score;
        hud_display(tetris);
        refresh();
        for (int i = 0; i < 100 && !tetris->end; i++) {
            usleep(10000 / tetris->level);
            tetris->decalage -= 10000 / tetris->level;
            event(tetris);
        }
    }
    return (0);
}

void init_colors(void)
{
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(4, COLOR_RED, COLOR_RED);
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
}

int init_play(tetris_t *tetris, flag_t *flags)
{
    char buf;

    tetris->win = initscr();
    tetris->highscore = recup_highscore();
    init_colors();
    tetris->decalage = clock();
    if (flags->debug)
        while (!read(0, &buf, 1));
    if (!tetris->tetriminos->max)
        exit(0);
    tetris->map->next =
    tetris->tetriminos->elements[rand()%tetris->tetriminos->max];
    nodelay(tetris->win, true);
    noecho();
    curs_set(0);
    popup("Please enlarge your terminal", tetris);
    play(tetris, flags);
    change_highscore(tetris);
    endwin();
    return (0);
}
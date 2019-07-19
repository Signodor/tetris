/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** flag
*/

#ifndef FLAG_H_
#define FLAG_H_

#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>

typedef struct flag
{
    char help;

    int start_level;

    char *left;
    char *right;
    char *turn;
    char *drop;
    char *quit;
    char *pause;

    int width;
    int height;

    char no_next;

    char debug;

    char **keys;
} flag_t;

flag_t *flag_create(int argc, char **argv, char **env);

void set_keys(flag_t *flags, char **argv);

void set_default_values(flag_t *flags, char **env);

#endif /* !FLAG_H_ */

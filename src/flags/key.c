/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** key
*/

#include "my.h"
#include "prototypes.h"

char *get_term(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "TERM=", 5))
            continue;
        return (env[i] + 5);
    }
    return (NULL);
}

void set_default_values(flag_t *flags, char **env)
{
    char bp[1024];

    if (tgetent(bp, get_term(env)) <= 0)
        error("Impossible to get terminal");
    flags->help = false;
    flags->start_level = 1;
    flags->left = my_strdup(tigetstr("kcub1"));
    flags->right = my_strdup(tigetstr("kcuf1"));
    flags->turn = my_strdup(tigetstr("kcuu1"));
    flags->drop = my_strdup(tigetstr("kcud1"));
    flags->quit = my_strdup("q");
    flags->pause = my_strdup(" ");
    flags->height = 20;
    flags->width = 10;
    flags->no_next = false;
    flags->debug = false;
}
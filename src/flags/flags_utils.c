/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** flags_utils
*/

#include "prototypes.h"

void check_keys(char *key, char **argv)
{
    char c;

    if (!my_strlen(key) || *key == '=')
        help(argv);
}

void set_keys(flag_t *flags, char **argv)
{
    flags->keys = malloc(sizeof(char *) * 7);

    flags->keys[0] = flags->left;
    flags->keys[1] = flags->right;
    flags->keys[2] = flags->turn;
    flags->keys[3] = flags->drop;
    flags->keys[4] = flags->quit;
    flags->keys[5] = flags->pause;
    flags->keys[6] = NULL;
    for (int i = 0; flags->keys[i]; i++)
        check_keys(flags->keys[i], argv);
}

void error(char const *msg)
{
    my_fputstr(2, msg);
    exit(84);
}
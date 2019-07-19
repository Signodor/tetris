/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** prototypes
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>
#include <errno.h>
#include <get_next_line.h>
#include <signal.h>
#include <ncurses.h>
#include <time.h>

#include "vector.h"
#include "command.h"
#include "my.h"
#include "tetriminos.h"
#include "map.h"
#include "tetris.h"
#include "flag.h"
#include "score.h"

int init_play(tetris_t *tetris, flag_t *flags);
int event(tetris_t *tetris);

char **init_tab(int width, int height);

void debug_mode(flag_t *flags, vector_t *vec);
void tetrisplay(vector_t *vec);

void popup(char *str, tetris_t *tetris);

void free_str_to_tab(char **tab);

void error(char const *msg);

int help(char **argv);
#endif /* !PROTOTYPES_H_ */

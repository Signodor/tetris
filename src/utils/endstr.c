/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** endstr
*/

#include <unistd.h>
#include "my.h"
#include <sys/stat.h>

int end_tetriminos(char const *filepath, char const *filename)
{
    struct stat filestat;

    if (my_strlen(filename) <= my_strlen(".tetrimino"))
        return (0);
    if (my_strcmp(filename + my_strlen(filename) - 10, ".tetrimino"))
        return (0);
    if (stat(filepath, &filestat))
        return (0);
    if (!S_ISREG(filestat.st_mode) || access(filepath, R_OK))
        return (0);
    return (1);
}
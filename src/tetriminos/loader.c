/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** loader
*/

#include "prototypes.h"

int load_params(tetriminos_t *tetrimino, int fd, flag_t *flags)
{
    char *line = get_next_line(fd);
    char **tab = str_to_tab(line, ' ');

    if (!tab || !tab[0] || !tab[1] || !tab[2])
        return (-1);
    tetrimino->width = my_getnbr(tab[0]);
    tetrimino->height = my_getnbr(tab[1]);
    tetrimino->color = my_getnbr(tab[2]);
    if (tetrimino->width <= 0 || tetrimino->width > flags->width
    || tetrimino->height <= 0 || tetrimino->height > flags->height ||
    tetrimino->color < 0)
        return (-1);
    free(line);
    free_str_to_tab(tab);
    return (0);
}

char *refract(int *length, int fd, int width)
{
    char *back  = malloc(sizeof(char) * (width + 1));
    char *line = get_next_line(fd);
    int index = 0;

    (*length) = 0;
    if (!line || !back)
        return (NULL);
    for (int i = 0; i < width; i++) {
        back[i] = line[index] == 0 ? ' ' : line[index];
        (*length) += line[index] != 0;
        if (back[i] != ' ' && back[i] != '*')
            return (NULL);
        index += line[index] != 0;
    }
    back[width] = 0;
    free(line);
    return (back);
}

int load_map(tetriminos_t *tetrimino, int fd)
{
    int back = 0;

    tetrimino->length = malloc(sizeof(int) * tetrimino->height);
    tetrimino->body = malloc(sizeof(char *) * tetrimino->height);
    if (!tetrimino->body)
        return (-1);
    for (int i = 0; i < tetrimino->height; i++) {
        if (!(tetrimino->body[i] =
        refract(tetrimino->length + i, fd, tetrimino->width)))
            return (-1);
    }
    return (0);
}

int tetrimino_load(tetriminos_t *tetrimino, char *filepath, flag_t *flags)
{
    int fd = open(filepath, O_RDONLY);
    char *content;

    if (load_params(tetrimino, fd, flags) == -1) {
        while ((content = get_next_line(fd)));
        free(content);
        return (-1);
    }
    if (load_map(tetrimino, fd) == -1) {
        while ((content = get_next_line(fd)));
        free(content);
        return (-1);
    }
    while ((content = get_next_line(fd)));
    free(content);
    free(filepath);
    close(fd);
    return (0);
}
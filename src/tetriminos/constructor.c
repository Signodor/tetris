/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** constructor
*/

#include "prototypes.h"

tetriminos_t *tetrimino_create(char *filepath, char *filename, flag_t *flags)
{
    tetriminos_t *tetrimino = malloc(sizeof(tetriminos_t));

    if (!tetrimino || !end_tetriminos(filepath, filename))
        return (NULL);
    if (tetrimino_load(tetrimino,
    my_strconcat("tetriminos/", filename), flags) == -1)
        tetrimino->body = NULL;
    tetrimino->name = my_strdup(filename);
    tetrimino->name[my_strlen(filename) - 10] = '\0';
    tetrimino->x = 0;
    tetrimino->y = 0;
    return (tetrimino);
}

tetriminos_t *tetriminos_spawn(tetriminos_t *src, flag_t *flags)
{
    tetriminos_t *dst = malloc(sizeof(tetriminos_t));

    dst->body = malloc(sizeof(char *) * src->height);
    for (int i = 0; i < src->height; i++) {
        dst->body[i] = malloc(src->width + 1);
        for (int j = 0; j < src->width; j++)
            dst->body[i][j] = src->body[i][j];
        dst->body[i][src->width] = 0;
    }
    dst->x = (flags->width - 1) / 2 - (src->width - 1) / 2;
    while (dst->x + src->width > flags->width)
        dst->x--;
    dst->y = src->height * -1;
    dst->color = src->color;
    dst->width = src->width;
    dst->height = src->height;
    dst->name = my_strdup(src->name);
    return (dst);
}

void tetrisplay(vector_t *vec)
{
    tetriminos_t *tetri;

    my_printf("Tetriminos : %d\n", vec->max);
    for (int i = 0; i < vec->max; i++) {
        my_printf("Tetriminos : ");
        tetri = vec->elements[i];
        my_printf("Name %s : ", tetri->name);
        if (tetri->body == NULL) {
            my_printf("Error\n");
            continue;
        }
        my_printf("Size %d*%d : Color %d :\n", tetri->width,
        tetri->height, tetri->color);
        for (int j = 0; j < tetri->height; j++)
            display_line(tetri->body[j], tetri->length[j]);
    }
}

void delete_useless(vector_t *vec)
{
    tetriminos_t *curr;
    int i = 0;

    while (i < vec->max) {
        curr = vec->elements[i];
        if (!curr->body) {
            vector_pop_this(vec, curr);
        } else
            i++;
    }
}

vector_t *load_tetriminos(flag_t *flags)
{
    vector_t *tetriminos = vector_create();
    char *path = getcwd(NULL, 0);
    DIR *dir = opendir("./tetriminos");
    struct dirent *fil;

    if (!dir || !path)
        error("Cannot open tetriminos folder");
    path = my_strconcat(path, "/tetriminos/");
    while ((fil = readdir(dir))) {
        if (fil->d_type != 010)
            continue;
        vector_append(tetriminos,
        tetrimino_create(my_strconcat(path, fil->d_name), fil->d_name, flags));
    }
    if (closedir(dir))
        error("Cannot close directory (wtf)");
    tetriminos_sort(tetriminos);
    return (tetriminos);
}
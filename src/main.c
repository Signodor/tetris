/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** main
*/

#include "prototypes.h"

int help(char **argv)
{
    my_printf("Usage:\t%s [options]\nOptions:\n", argv[0]);
    my_printf(" --help\t\t\tDisplay this help\n");
    my_printf(" -L --level={num}\tStart tetris at level num (def: 1)\n");
    my_printf(" -l --key-left={K}\tMove the tetrimino LEFT using the K key ");
    my_printf("(def: left arrow)\n -r --key-right={K}\tMove the tetrimino ");
    my_printf("RIGHT using the K key (def: right arrow)\n");
    my_printf(" -t --key-turn={K}\tTURN the tetrimino clockwise 90d using");
    my_printf("the K key (def: top arrow)\n");
    my_printf(" -d --key-drop={K}\tDROP the tetrimino using the K key (def:");
    my_printf(" down arrow key)\n -q --key-quit={K}\tQUIT the game using the");
    my_printf(" K key (def: 'q' key)\n -p --key-pause={K}\tPAUSE/RESTART the");
    my_printf(" game using the K key (def: space bar)\n --map-size={row,col}");
    my_printf("\tSet the numbers of rows and columns of the map (def: 20,10)");
    my_printf("\n -w --without-next\tHide next tetrimino (def: false)\n");
    my_printf(" -D --debug\t\tDebug mode (def: false)\n");
    exit(0);
}

int error_gestion(flag_t *flags)
{
    list_t *list = list_create();
    element_t *elmt = NULL;
    int ret = 0;

    if (flags->height <= 0 || flags->width <= 0 || flags->start_level <= 0)
        ret = 84;
    for (int i = 0; flags->keys[i]; i++) {
        for (elmt = list->first; elmt && !ret; elmt = elmt->next)
            ret = !my_strcmp((char *)elmt->content, flags->keys[i]) ? 84 : 0;
        if (ret)
            break;
        append(list, flags->keys[i]);
    }
    while (list->nb_elem)
        pop(list);
    free(list);
    return (ret);
}

int start(vector_t *vec, flag_t *flags, tetris_t *tetris, char *str)
{
    if (!vec)
        return (84);
    srand(time(NULL));
    tetris->tetriminos = vec;
    if (flags->help)
        return (1);
    if (error_gestion(flags))
        return (84);
    if (flags->debug)
        debug_mode(flags, vec);
    delete_useless(tetris->tetriminos);
    return (init_play(tetris, flags));
}

void free_all(tetris_t *tetris)
{
    for (int i = 0; i < tetris->tetriminos->max; i++)
        tetriminos_destroy(tetris->tetriminos->elements[i]);
    vector_delete(tetris->tetriminos);
    for (int i = 0; i < tetris->map->height; i++)
        free(tetris->map->body[i]);
    free(tetris->map->body);
    free(tetris->map);
    free(tetris);
}

int main(int argc, char **argv, char **env)
{
    flag_t *flags = flag_create(argc, argv, env);
    tetris_t *tetris = tetris_create(flags);
    vector_t *vec = load_tetriminos(flags);
    int res = start(vec, flags, tetris, argv[0]);

    if (res == 1)
        help(argv);
    for (int i = 0; flags->keys[i]; i++)
        free(flags->keys[i]);
    free(flags->keys);
    free(flags);
    free_all(tetris);
    return (res);
}
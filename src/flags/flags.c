/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** flags
*/

#include "prototypes.h"

struct option options[] = {
    {"help", no_argument, 0, 'h'},
    {"level", required_argument, 0, 'L'},
    {"key-left", required_argument, 0, 'l'},
    {"key-right", required_argument, 0, 'r'},
    {"key-turn", required_argument, 0, 't'},
    {"key-drop", required_argument, 0, 'd'},
    {"key-quit", required_argument, 0, 'q'},
    {"key-pause", required_argument, 0, 'p'},
    {"map-size", required_argument, 0, 'm'},
    {"without-next", no_argument, 0, 'w'},
    {"debug", no_argument, 0, 'D'}};

static int and_other_arg(flag_t *flags, int opt)
{
    switch (opt) {
        case 'q' : flags->quit = my_strdup(optarg);
            return (0);
        case 'p' : flags->pause = my_strdup(optarg);
            return (0);
        case 'w' : flags->no_next = true;
            return (0);
        case 'D' : flags->debug = true;
            return (0);
        default:
            return (-1);
    }
    return (0);
}

static int handle_each_arg(flag_t *flags, int opt)
{
    char **map;

    switch (opt) {
        case 'm' :
            map = str_to_tab(optarg, ',');
            if (!map || !map[0] || !map[1])
                return (-1);
            flags->height = my_getnbr(map[0]);
            flags->width = my_getnbr(map[1]);
            return (0);
        case 't' : flags->turn = my_strdup(optarg);
            break;
        case 'd' : flags->drop = my_strdup(optarg);
            break;
        default:
            return (and_other_arg(flags, opt));
    }
    return (0);
}

static int get_opts(int argc, char **argv, flag_t *flags)
{
    int opt;
    int longind;
    int back = 0;

    while ((opt = getopt_long(argc, argv, "h:L:l:r:t:d:q:p:m:wD",
    options, &longind)) != -1 && !back) {
        switch (opt) {
            case 'h' : flags->help = true;
                break;
            case 'L' : flags->start_level = my_getnbr(optarg);
                break;
            case 'l' : flags->left = my_strdup(optarg);
                break;
            case 'r' : flags->right = my_strdup(optarg);
                break;
            default:
                back = handle_each_arg(flags, opt);
        }
    }
    return (back);
}

flag_t *flag_create(int argc, char **argv, char **env)
{
    flag_t *flags = malloc(sizeof(flag_t));

    if (!flags)
        error("No memory");
    set_default_values(flags, env);
    opterr = 0;
    if (get_opts(argc, argv, flags) || optind != argc)
        help(argv);
    if (flags->width <= 0 || flags->height <= 0 || flags->start_level < 0)
        help(argv);
    set_keys(flags, argv);
    return (flags);
}
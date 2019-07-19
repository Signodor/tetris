/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** debug_mode
*/

#include "prototypes.h"
#include <termios.h>

int dispcouille(char *couille)
{
    for (int i = 0; couille[i]; i++) {
        if (couille[i] == 27)
            my_printf("^E");
        else if (couille[i] == 32)
            my_printf("(space)");
        else
            my_printf("%c", couille[i]);
    }
    my_printf("\n");
    return (0);
}

void debug_mode(flag_t *f, vector_t *tetriminos)
{
    int i = 0;

    my_printf("*** DEBUG MODE ***\nKey Left : ");
    dispcouille(f->left);
    my_printf("Key Right : ");
    dispcouille(f->right);
    my_printf("Key Turn : ");
    dispcouille(f->turn);
    my_printf("Key Drop : ");
    dispcouille(f->drop);
    my_printf("Key Quit : ");
    dispcouille(f->quit);
    my_printf("Key Pause : ");
    dispcouille(f->pause);
    my_printf("Next : %s\n", !f->no_next ? "Yes" : "No");
    my_printf("Level : %d\n", f->start_level);
    my_printf("Size : %d*%d\n", f->height, f->width);
    tetrisplay(tetriminos);
    my_printf("Press any key to start Tetris\n");
}
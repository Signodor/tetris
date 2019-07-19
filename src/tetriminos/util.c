/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** util
*/

#include "tetriminos.h"

void display_line(char *str, int length)
{
    for (int i = 0; i < length; i++)
        my_printf("%c", str[i]);
    my_printf("\n");
}
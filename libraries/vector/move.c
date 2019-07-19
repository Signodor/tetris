/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** move
*/

#include "vector.h"

int vector_move(vector_t *vector, int start, int end, int dec)
{
    if (!vector || end < start || !dec || end >= vector->max || start < 0)
        return (-1);
    if (start + dec < 0 || end + dec >= vector->length)
        return (-1);
    if (dec < 0)
        for (int i = start; i <= end; i++)
            vector->elements[i + dec] = vector->elements[i];
    else
        for (int i = end; i >= start; i--)
            vector->elements[i + dec] = vector->elements[i];
    return (0);
}
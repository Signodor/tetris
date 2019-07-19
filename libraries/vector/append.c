/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** append
*/

#include "vector.h"
int vector_realloc(vector_t *vector, int many);

int vector_append(vector_t *vector, void *content)
{
    if (!vector || !content)
        return (-1);
    if (vector->max + 1 >= vector->length)
        if (vector_realloc(vector, 16))
            return (-1);
    vector->elements[vector->max] = content;
    vector->max++;
    return (0);
}

int vector_insert_at(vector_t *vector, void *content, int id)
{
    if (!vector)
        return (-1);
    if (vector->max + 1 >= vector->length)
        if (vector_realloc(vector, 16))
            return (-1);
    if (vector_move(vector, id, vector->max, 1))
        return (-1);
    vector->elements[id] = content;
    vector->max++;
    return (0);
}

int vector_insert(vector_t *vector, void *content)
{
    return (vector_insert_at(vector, content, 0));
}
/*
** EPITECH PROJECT, 2018
** malloc + initialized
** File description:
** my_calloc
*/

#include "stdlib.h"
void *my_memset(void *dst, int c, size_t n);

void *my_calloc(size_t nb_elem, size_t type_size)
{
    void *ptr = malloc(nb_elem * type_size);

    if (ptr)
        my_memset(ptr, 0, nb_elem * type_size);
    return (ptr);
}
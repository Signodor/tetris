/*
** EPITECH PROJECT, 2018
** memset
** File description:
** my_memset
*/

#include "stdlib.h"

void *my_memset(void *dst, int c, size_t n)
{
    char *dest = dst;

    if (n) {
        for (int i = 0; i < n; i++)
            *dest++ = c;
    }
    return (dst);
}
/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** for_each
*/

#include "my.h"

int for_each(list_t *list, void (* func)(void *, int id))
{
    element_t *current;

    if (!list || !func)
        return (-1);
    current = list->first;
    while (current) {
        func(current->content, current->id);
        current = current->next;
    }
    return (0);
}
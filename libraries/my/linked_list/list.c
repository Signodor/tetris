/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** list
*/

#include "my.h"

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (!list)
        return (NULL);
    list->first = NULL;
    list->nb_elem = 0;
    return (list);
}

element_t *list_get(list_t *list, int index)
{
    int current_index = 0;
    element_t *curr = list->first;

    while (current_index < index) {
        if (!curr)
            break;
        curr = curr->next;
        current_index++;
    }
    return (curr);
}
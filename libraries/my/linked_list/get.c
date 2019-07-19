/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** get
*/

#include "my.h"

element_t *get(list_t *list)
{
    return (list->first);
}

element_t *get_last(list_t *list)
{
    element_t *current = list->first;

    if (!current)
        return (NULL);
    while (current->next)
        current = current->next;
    return (current);
}

element_t *get_element(list_t *list, element_t *element)
{
    element_t *current = list->first;

    if (!list->first || !element)
        return (NULL);
    if (list->first == element)
        return (list->first);
    while (current) {
        if (current == element)
            return (current);
        current = current->next;
    }
    return (NULL);
}

element_t *get_content(list_t *list, void *content)
{
    element_t *current = list->first;

    if (!list->first)
        return (NULL);
    if (list->first->content == content)
        return (list->first);
    while (current) {
        if (current->content == content)
            return (current);
        current = current->next;
    }
    return (NULL);
}

element_t *get_id(list_t *list, size_t id)
{
    element_t *current = list->first;

    if (!list->first)
        return (NULL);
    if (list->first->id == id)
        return (list->first);
    while (current) {
        if (current->id == id)
            return (current);
        current = current->next;
    }
    return (NULL);
}
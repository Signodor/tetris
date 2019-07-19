/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** pop
*/

#include "my.h"

element_t *pop(list_t *list)
{
    element_t *element = list->first;

    if (!element)
        return (NULL);
    list->first = element->next;
    list->nb_elem--;
    elements_decrements(list->first);
    if (list->first)
        list->first->before = NULL;
    element->next = NULL;
    return (element);
}

element_t *pop_last(list_t *list)
{
    element_t *current = list->first;
    element_t *element;

    if (!current)
        return (NULL);
    list->nb_elem--;
    if (!current->next)
        return (pop(list));
    while (current->next->next)
        current = current->next;
    element = current->next;
    current->next = NULL;
    element->before = NULL;
    return (element);
}

element_t *pop_element(list_t *list, element_t *element)
{
    element_t *current = list->first;
    element_t *tmp;

    if (!list || !list->first || !element)
        return (NULL);
    if (list->first == element)
        return (pop(list));
    while (current->next) {
        if (current->next == element) {
            tmp = current->next;
            current->next = current->next->next;
            list->nb_elem--;
            elements_decrements(current->next);
            return (tmp);
        }
        current = current->next;
    }
    return (NULL);
}

element_t *pop_content(list_t *list, void *content)
{
    element_t *current = list->first;
    element_t *tmp;

    if (!list || !list->first)
        return (NULL);
    if (list->first->content == content)
        return (pop(list));
    while (current->next) {
        if (current->next->content == content) {
            tmp = current->next;
            current->next = current->next->next;
            list->nb_elem--;
            elements_decrements(current->next);
            return (tmp);
        }
        current = current->next;
    }
    return (NULL);
}

element_t *pop_id(list_t *list, size_t id)
{
    element_t *current = list->first;
    element_t *tmp;

    if (!list || !list->first)
        return (NULL);
    if (list->first->id == id)
        return (pop(list));
    while (current->next) {
        if (current->next->id == id) {
            tmp = current->next;
            current->next = current->next->next;
            list->nb_elem--;
            elements_decrements(current->next);
            return (tmp);
        }
        current = current->next;
    }
    return (NULL);
}
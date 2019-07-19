/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** pushing
*/

#include "my.h"

void insert(list_t *list, void *content)
{
    element_t *element = malloc(sizeof(element_t));

    if (!list || !element)
        return;
    element->content = content;
    element->before = NULL;
    element->next = list->first;
    if (element->next)
        element->next->before = element;
    element->id = 0;
    list->first = element;
    list->nb_elem++;
    elements_increments(element->next);
}

void append(list_t *list, void *content)
{
    element_t *element = malloc(sizeof(element_t));
    element_t *current = list->first;
    size_t id = 1;

    if (!element)
        return;
    element->next = NULL;
    element->content = content;
    if (!current)
        return (insert(list, content));
    list->nb_elem++;
    while (current->next) {
        current = current->next;
        id++;
    }
    element->id = id;
    element->before = current;
    current->next = element;
}
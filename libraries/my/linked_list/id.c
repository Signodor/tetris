/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** id
*/

#include "my.h"

void elements_increments(element_t *current)
{
    while (current) {
        current->id++;
        current = current->next;
    }
}

void elements_decrements(element_t *current)
{
    while (current) {
        current->id--;
        current = current->next;
    }
}

void elements_increments_back(element_t *current)
{
    while (current) {
        current->id++;
        current = current->before;
    }
}

void elements_decrements_back(element_t *current)
{
    while (current) {
        current->id--;
        current = current->before;
    }
}
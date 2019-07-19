/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** swapping two numbers
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}

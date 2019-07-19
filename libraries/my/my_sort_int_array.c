/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** sorting an array of int in ascent order
*/

void my_check_and_swap(int *first, int *second)
{
    int tmp;

    if (*first > *second) {
        tmp = *first;
        *first = *second;
        *second = tmp;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0 ; i < size ; i++) {
        for (int j = i + 1 ; j < size ; j++) {
            my_check_and_swap(array + i, array + j);
        }
    }
}

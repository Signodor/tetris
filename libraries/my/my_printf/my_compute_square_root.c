/*
** EPITECH PROJECT, 2018
** my_square_root
** File description:
** return the square root of a number
*/

int my_compute_square_root(int nb)
{
    for (int i = 0 ; i < 46341 ; i++) {
        if (i * i == nb)
            return (i);
        if (i * i > nb)
            return (0);
    }
    return (0);
}

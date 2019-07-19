/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** compute power in recursive
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return nb*my_compute_power_rec(nb, p - 1);
}

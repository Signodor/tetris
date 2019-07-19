/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** find the prime nmber greater or equal to nb
*/

int my_find_prime_sup_rec(int nb)
{
    if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
        return (1);
    if (nb <= 1 || nb%2 == 0 || nb%3 == 0 || nb%5 == 0 || nb%7 == 0)
        return (0);
    for (int i = 3 ; i <= nb / 11 ; i += 2)
        if (nb%i == 0)
            return (0);
    return (1);
}

int my_find_prime_sup(int nb)
{
    for (; !(my_find_prime_sup_rec(nb)) ; nb++);
    return (nb);
}

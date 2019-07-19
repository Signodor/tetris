/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** return if the number is prime or not
*/

int my_is_prime(int nb)
{
    if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
        return (1);
    if (nb <= 1 || nb%2 == 0 || nb%3 == 0 || nb%5 == 0 || nb%7 == 0)
        return (0);
    for (int i = 3 ; i <= nb/11 ; i += 2)
        if (nb%i == 0)
            return (0);
    return (1);
}

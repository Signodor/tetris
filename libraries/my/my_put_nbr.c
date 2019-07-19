/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** print int number
*/

void my_putchar(char c);

int my_powe(int a)
{
    int result = 1;
    while (a >= 1) {
        result *= 10;
        a--;
    }
    return (result);
}

int my_put_nbr_recur(int n)
{
    if (n >= 10)
        my_put_nbr_recur(n / 10);
    my_putchar('0' + (n % 10));
}

int my_test_limit_put_nbr(int n)
{
    if (n == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        n = 147483648;
    }
    if (n < 0) {
        my_putchar('-');
        n *= -1;
    }
    return (n);
}

int my_put_nbr(int n)
{
    int i;
    int nb;

    n = my_test_limit_put_nbr(n);
    nb = n;
    for (i = 0 ; nb > 10 ; i++)
        nb /= 10;
    for (int j = my_powe(i) ; i >= 0 ; j /= 10)
    {
        my_putchar('0' + n/j);
        n %= j;
        i--;
    }
    return (0);
}

/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** display n if negative or p else
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return (0);
}

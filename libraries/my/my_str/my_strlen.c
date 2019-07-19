/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** getting the length of a string
*/

int my_strlen(char const *str)
{
    int i;

    if (!str)
        return (0);
    for (i = 0; str[i] != 0; i++);
    return (i);
}

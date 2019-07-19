/*
** EPITECH PROJECT, 2018
** my str n cat
** File description:
** str n cat
*/

int my_strlen_strncat(char const *str)
{
    int i;

    for (i = 0 ; str[i] != 0 ; i++);
    return (i);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int max = my_strlen_strncat(dest);
    int i;

    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[max + i] = src[i];
    dest[max + i] = '\0';
    return (dest);
}

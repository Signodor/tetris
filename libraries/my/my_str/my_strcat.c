/*
** EPITECH PROJECT, 2018
** my str cat
** File description:
** str cat
*/

int my_strlen_strcat(char const *str)
{
    int i;

    for (i = 0 ; str[i] != 0 ; i++);
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int max = my_strlen_strcat(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[max + i] = src[i];
    dest[max + i] = '\0';
    return (dest);
}

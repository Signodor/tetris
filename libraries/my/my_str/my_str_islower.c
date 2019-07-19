/*
** EPITECH PROJECT, 2018
** my str lower
** File description:
** string lower
*/

int my_str_islower(char *str)
{
    while (*str != '\0') {
        if (*str < 'a' || *str > 'z')
            return (0);
        str++;
    }
    return (1);
}

/*
** EPITECH PROJECT, 2018
** my str lower
** File description:
** string lower
*/

int my_str_isupper(char *str)
{
    while (*str != '\0') {
        if (*str < 'A' || *str > 'Z')
            return (0);
        str++;
    }
    return (1);
}

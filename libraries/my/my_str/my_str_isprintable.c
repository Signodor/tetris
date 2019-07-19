/*
** EPITECH PROJECT, 2018
** salut
** File description:
** salut
*/

int my_str_isprintable(char *str)
{
    while (*str != '\0') {
        if (*str < 32 || *str == 127)
            return (0);
        str++;
    }
    return (1);
}

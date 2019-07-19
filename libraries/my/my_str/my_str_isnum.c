/*
** EPITECH PROJECT, 2018
** y str is num
** File description:
** same
*/

int my_str_isnum(char *str)
{
    while (*str != '\0') {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

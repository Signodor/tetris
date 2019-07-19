/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** my str is alpha
*/

int my_str_isalpha(char const *str)
{
    while (*str != '\0') {
        if (*str < 'A' || (*str > 'Z' && *str < 'a') || *str > 'z')
            return (0);
        str++;
    }
    return (1);
}

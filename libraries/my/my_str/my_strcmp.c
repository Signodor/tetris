/*
** EPITECH PROJECT, 2018
** my string compare
** File description:
** string comparing
*/

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return (-1);
    for (int i = 0;; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return (s1[i] - s2[i]);
    }
    return (0);
}
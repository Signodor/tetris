/*
** EPITECH PROJECT, 2018
** my string compare n bytes
** File description:
** string comparing
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0')
            return (s1[i] - s2[i]);
    }
    return (0);
}

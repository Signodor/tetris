/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** copy string n chars
*/

int my_strlen_strncpy(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (n > my_strlen_strncpy(src))
        dest[i] = '\0';
    return (dest);
}

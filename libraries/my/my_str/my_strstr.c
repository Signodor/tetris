/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** str str
*/

int my_strlen_strstr(char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++);
    return (i);
}

void deplace(char a, char b, int length, int *j)
{
    if (a != b)
        *j = length + 1;
}

char *my_strstr(char *str, char const *to_find)
{
    char *index;
    int length_tofind = my_strlen_strstr(to_find);
    int j;

    for (int i = 0; str[i] != '\0'; i++) {
        index = str + i;
        for (j = 0; j < length_tofind && str[j] != '\0'; j++)
            deplace(str[i + j], to_find[j], length_tofind, &j);
        if (j == length_tofind)
            return (index);
    }
    return (0);
}

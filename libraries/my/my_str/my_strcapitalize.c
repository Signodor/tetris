/*
** EPITECH PROJECT, 2018
** capitalize
** File description:
** capitalize
*/

char *my_strlowcase_capitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}

int my_isin(char const *str, char a)
{
    while (*str != '\0') {
        if (*str == a)
            return (1);
        str++;
    }
    return (0);
}

char *my_strcapitalize(char *str)
{
    char a[] = " -+";

    my_strlowcase_capitalize(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' &&
            (i == 0 || my_isin(a, str[i-1])))
            str[i] -= 32;
    }
    return (str);
}

/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** revision  string
*/

int my_strlen_revstr(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_revstr(char *str)
{
    char temp;
    int length = my_strlen_revstr(str);

    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return (str);
}

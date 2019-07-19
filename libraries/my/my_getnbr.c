/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** converting string in int
*/

int get_value(long ret, char signe)
{
    return ((int)(ret*(signe*-2 + 1)));
}

int insert_value(long *ret, char digit, char signe)
{
    *ret = *ret * 10 + digit - '0';
    if (*ret*(signe*-2 + 1) != get_value(*ret, signe))
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    long ret = 0;
    char signe = 0;

    if (!str)
        return (-84);
    while (*str == ' ')
        str++;
    for (int i = 0 ; str[i] != 0 ; i++) {
        if (str[i] == '+')
            continue;
        if (str[i] == '-') {
            signe = !signe;
            continue;
        } else if (!(str[i] >= '0' && str[i] <= '9')) {
            return (get_value(ret, signe));
        }
        if (insert_value(&ret, str[i], signe))
            return (0);
    }
    return (get_value(ret, signe));
}

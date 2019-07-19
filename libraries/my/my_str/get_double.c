/*
** EPITECH PROJECT, 2018
** 101pong_2018
** File description:
** get_double
*/

int handle_content(char c, double *operand, double *result)
{
    if (c < '0' || c > '9') {
        if (c == '.' && *operand == 0)
            (*operand) = 10;
        else
            return (-1);
    } else {
        if (*operand) {
            (*result) += (c - '0')/(*operand);
            (*operand) *= 10;
        } else {
            (*result) *= 10;
            (*result) += c - '0';
        }
    }
    return (0);
}

double my_get_double(char const *str)
{
    double operand = 0;
    double result = 0;
    int signe;

    if (!str)
        return (-84.);
    signe = *str == '-';
    for (int i = signe; str[i]; i++)
        if (handle_content(str[i], &operand, &result) == -1)
            return (-84);
    return (result * (1 - signe*2));
}
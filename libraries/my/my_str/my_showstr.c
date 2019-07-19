/*
** EPITECH PROJECT, 2018
** show str
** File description:
** show str
*/

void my_putchar(char c);

void print_hexa(char value)
{
    if (value < 10)
        my_putchar('0' + value);
    else
        my_putchar('a' - 10 + value);
}

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] != 127) {
            my_putchar(str[i]);
            continue;
        }
        my_putchar('\\');
        print_hexa(str[i]/16);
        print_hexa(str[i]%16);
    }
    my_putchar('\n');
    return (0);
}

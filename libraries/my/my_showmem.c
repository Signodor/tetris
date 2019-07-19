/*
** EPITECH PROJECT, 2018
** my showmen
** File description:
** my showmen
*/

void my_putchar(char c);

int my_power_showmem(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return nb*my_power_showmem(nb, p - 1);
}

void print_hexa_showmem(char value)
{
    if (value < 10)
        my_putchar('0' + value);
    else
        my_putchar('a' + value - 10);
}

void my_printchepa(char const *str)
{
    char isEnded = 0;

    for (int i = 0; i < 16; i += 2) {
        if (str[i] == '\0' || isEnded) {
            isEnded = 1;
            my_putchar(' ');
            my_putchar(' ');
        } else {
            print_hexa_showmem(str[i] / 16);
            print_hexa_showmem(str[i] % 16);
        }
        if (str[i+1] == '\0' || isEnded) {
            isEnded = 1;
            my_putchar(' ');
            my_putchar(' ');
        } else {
            print_hexa_showmem(str[i+1] / 16);
            print_hexa_showmem(str[i+1] % 16);
        }
        my_putchar(' ');
    }
}

void print_line(char const *str, int id)
{
    for (int i = 0; i < 7; i++)
        print_hexa_showmem(id*16 / my_power_showmem(16, 7 - i));
    my_putchar('0');
    my_putchar(':');
    my_putchar(' ');
    my_putchar(' ');
    my_printchepa(str);
    for (int i = 0; i < 16 && str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
        else
            my_putchar('.');
    }
    my_putchar('\n');
}

int my_showmem(char const *str, int size)
{
    for (int i = 0; i < size; i++) {
        print_line(str, i);
        str += 16;
    }
    return (0);
}

/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_print_format_spestring
*/

#include "my_printf.h"

int my_print_spestring(char *buffer, char c)
{
    if (c < 32 || c >= 127) {
        buffer[0] = '\\';
        buffer[1] = c/64 + '0';
        buffer[2] = c/8%8 + '0';
        buffer[3] = c%8 + '0';
        return (3);
    }
    buffer[0] = c;
    return (0);
}

int my_print_format_spestring(va_list *list, flags_t *flags)
{
    const char *str = va_arg(*list, void *);
    int length = 0;
    int counter = 0;
    char *buffer;

    flags->zero = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127)
            length += 3;
        length++;
    }
    buffer = my_calloc(length + 1, sizeof(char));
    for (int i = 0; str[i]; i++)
        counter += my_print_spestring(buffer + counter + i, str[i]);
    my_print_format_flag_number(flags, buffer, length);
}
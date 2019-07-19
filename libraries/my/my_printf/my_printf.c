/*
** EPITECH PROJECT, 2018
** PSU_my_printf_bootstrap_2018
** File description:
** my_printf
*/

#include "my_printf.h"

const format_t formats[] = {{"d", my_print_integer},
                            {"i", my_print_integer},
                            {"hd", my_print_hinteger},
                            {"hi", my_print_hinteger},
                            {"hhd", my_print_hhinteger},
                            {"hhi", my_print_hhinteger},
                            {"ld", my_print_linteger},
                            {"li", my_print_linteger},
                            {"lld", my_print_llinteger},
                            {"lli", my_print_llinteger},
                            {"hhu", my_print_hhuinteger},
                            {"hu", my_print_huinteger},
                            {"u", my_print_uinteger},
                            {"lu", my_print_luinteger},
                            {"llu", my_print_lluinteger},
                            {"hhx", my_print_hhhexadecimal},
                            {"hx", my_print_hhexadecimal},
                            {"x", my_print_hexadecimal},
                            {"lx", my_print_lhexadecimal},
                            {"llx", my_print_llhexadecimal},
                            {"hhX", my_print_hhhexadecimal_maj},
                            {"hX", my_print_hhexadecimal_maj},
                            {"X", my_print_hexadecimal_maj},
                            {"lX", my_print_lhexadecimal_maj},
                            {"llX", my_print_llhexadecimal_maj},
                            {"hho", my_print_hhoctale},
                            {"ho", my_print_hoctale},
                            {"o", my_print_octale},
                            {"lo", my_print_loctale},
                            {"llo", my_print_lloctale},
                            {"hhb", my_print_hhbinary},
                            {"hb", my_print_hbinary},
                            {"b", my_print_binary},
                            {"lb", my_print_lbinary},
                            {"llb", my_print_llbinary},
                            {"c", my_print_format_char},
                            {"s", my_print_format_string},
                            {"S", my_print_format_spestring},
                            {"p", my_print_format_pointer},
                            {"f", my_print_format_double},
                            {"lf", my_print_format_double},
                            {"%", my_print_percent},
                            {0, 0}};

int my_printf_format(const char *format)
{
    for (int i = 0; formats[i].type; i++) {
        if (my_strncmp(formats[i].type,
        format, my_strlen(formats[i].type)) == 0)
            return (i);
    }
    return (8484);
}

int my_format_atoi(char const *str, int *length)
{
    int result = 0;

    for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
        result = result * 10 + str[i] - '0';
        (*length)++;
    }
    return (result);
}

int my_get_flags(char const *str, flags_t *flags)
{
    int length = 0;

    length += *str == '+' || *str == '-' || *str == '0' ||
    *str == '#' || *str == ' ' || *str == '.';
    flags->plus += *str == '+';
    flags->minus += *str == '-';
    flags->hashtag += *str == '#';
    flags->zero += *str == '0';
    flags->blank += *str == ' ';
    if (*str >= '1' && *str <= '9')
        flags->number = my_format_atoi(str, &length);
    if (*str == '.')
        flags->point = my_format_atoi(str + 1, &length);
    return (length);
}

int special_case(char const *format, int *i)
{
    if (format[*i] != '%') {
        my_putchar(format[*i]);
        return (1);
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    va_list list;
    flags_t *flags = my_calloc(1, sizeof(flags_t));
    int form;
    int tmp_i;

    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (special_case(format, &i))
            continue;
        my_memset(flags, 0, sizeof(flags_t));
        handle_wrong_one(&i, 0, 1);
        while (tmp_i = my_get_flags(format + i + 1, flags))
            i += tmp_i;
        form = my_printf_format(format + i + 1);
        if (handle_wrong_one(&i, form, 0))
            continue;
        formats[form].func(&list, flags);
        i += my_strlen(formats[form].type);
    }
    va_end(list);
}
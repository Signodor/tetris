/*
** EPITECH PROJECT, 2019
** MUL_2018_my_defender
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include "my.h"

int my_print_long(unsigned long long value, char *buffer, int index,
int point);
int my_print_signed_decimal(long long value, flags_t *flags);
int my_print_hhinteger(va_list *list, flags_t *flags);
int my_print_hinteger(va_list *list, flags_t *flags);
int my_print_integer(va_list *list, flags_t *flags);
int my_print_linteger(va_list *list, flags_t *flags);
int my_print_llinteger(va_list *list, flags_t *flags);
int my_print_hhuinteger(va_list *list, flags_t *flags);
int my_print_huinteger(va_list *list, flags_t *flags);
int my_print_uinteger(va_list *list, flags_t *flags);
int my_print_luinteger(va_list *list, flags_t *flags);
int my_print_lluinteger(va_list *list, flags_t *flags);
int my_print_hhhexadecimal(va_list *list, flags_t *flags);
int my_print_hhexadecimal(va_list *list, flags_t *flags);
int my_print_hexadecimal(va_list *list, flags_t *flags);
int my_print_lhexadecimal(va_list *list, flags_t *flags);
int my_print_llhexadecimal(va_list *list, flags_t *flags);
int my_print_hhhexadecimal_maj(va_list *list, flags_t *flags);
int my_print_hhexadecimal_maj(va_list *list, flags_t *flags);
int my_print_hexadecimal_maj(va_list *list, flags_t *flags);
int my_print_lhexadecimal_maj(va_list *list, flags_t *flags);
int my_print_llhexadecimal_maj(va_list *list, flags_t *flags);
int my_print_hhoctale(va_list *list, flags_t *flags);
int my_print_hoctale(va_list *list, flags_t *flags);
int my_print_octale(va_list *list, flags_t *flags);
int my_print_loctale(va_list *list, flags_t *flags);
int my_print_lloctale(va_list *list, flags_t *flags);
int my_print_hhbinary(va_list *list, flags_t *flags);
int my_print_hbinary(va_list *list, flags_t *flags);
int my_print_binary(va_list *list, flags_t *flags);
int my_print_lbinary(va_list *list, flags_t *flags);
int my_print_llbinary(va_list *list, flags_t *flags);
int my_print_format_char(va_list *list, flags_t *flags);
int my_print_format_string(va_list *list, flags_t *flags);
int my_print_pointer(unsigned int ptr, int end);
int my_print_format_pointer(va_list *list, flags_t *flags);
int my_print_hex(unsigned long long value, char *buffer, int index, int point);
int my_print_format_hexadecimal(unsigned long long value, flags_t *flags);
int my_print_ubinary(unsigned long long value, char *buffer, int index,
int point);
int my_print_format_binary(unsigned long long value, flags_t *flags);
int my_print_format_spestring(va_list *list, flags_t *flags);
int my_printf_format(const char *format);
int my_print_hex_maj(unsigned long long value, char *buffer, int index,
int point);
int my_print_format_hexadecimal_maj(unsigned long long value, flags_t *flags);
int my_print_udecimal(unsigned long long value, char *buffer,
int index, int point);
int my_print_un_decimal(unsigned long long value, flags_t *flags);
int my_print_uoctale(unsigned long long value, char *buffer, int index,
int point);
int my_print_format_octale(unsigned long long value, flags_t *flags);
int my_print_format_double(va_list *list, flags_t *flags);
unsigned int my_nbrlen_base(unsigned long long number, int base,
flags_t *flags);
void my_print_format_flag_number(flags_t *flags, char const *buffer,
int length);
void my_put_flag(flags_t *flags, int length);
int special_case(char const *format, int *i);
int my_get_flags(char const *str, flags_t *flags);
int my_format_atoi(char const *str, int *length);
int my_printf_format(const char *format);
int my_print_percent(va_list *list, flags_t *flags);

#endif /* !MY_PRINTF_H_ */

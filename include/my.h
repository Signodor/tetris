/*
** EPITECH PROJECT, 2018
** Library
** File description:
** my
*/

#include "stdlib.h"
#include "stdarg.h"
#include "unistd.h"

#ifndef MY_H_
#define MY_H_

typedef struct flags
{
    int minus;
    int zero;
    int plus;
    int blank;
    int hashtag;
    int number;
    int point;
} flags_t;

typedef struct format
{
    char *type;
    int (*func)(va_list *list, flags_t *flags);
} format_t;

typedef struct element
{
    void *content;
    size_t id;
    struct element *before;
    struct element *next;
} element_t;

typedef struct list
{
    element_t *first;
    size_t nb_elem;
} list_t;

list_t *list_create(void);
element_t *list_get(list_t *list, int index);

void insert(list_t *list, void *content);
void append(list_t *list, void *content);

element_t *pop(list_t *list);
element_t *pop_last(list_t *list);
element_t *pop_element(list_t *list, element_t *element);
element_t *pop_content(list_t *list, void *content);
element_t *pop_id(list_t *list, size_t id);

element_t *get(list_t *list);
element_t *get_last(list_t *list);
element_t *get_element(list_t *list, element_t *element);
element_t *get_content(list_t *list, void *content);
element_t *get_id(list_t *list, size_t id);

void elements_increments_back(element_t *current);
void elements_decrements_back(element_t *current);
void elements_increments(element_t *current);
void elements_decrements(element_t *current);

int get_value(long ret, char signe);
int insert_value(long *ret, char digit, char signe);
int my_powe(int a);
void my_put_nbr_recur(int n);
int my_test_limit_put_nbr(int n);
int my_strlen_revstr(char *str);
int my_power_showmem(int nb, int p);
void print_hexa_showmem(char value);
void my_printchepa(char const *str);
void print_line(char const *str, int id);
void print_hexa(char value);
void my_check_and_swap(int *first, int *second);
char *my_strlowcase_capitalize(char *str);
int my_isin(char const *str, char a);
int my_strlen_strcat(char const *str);
int my_strlen_strncat(char const *str);
int my_strlen_strncpy(char const *str);
int my_isalphanum(char c);
int my_array_counter(char *str);
int my_wordsize(char *str);
int my_find_prime_sup_rec(int nb);
void my_putchar(char c);
int my_isneg(int n);
int my_put_nbr(int n);
void my_swap(int *a, int *b);
void deplace(char a, char b, int length, int *j);
int my_strlen_strstr(char const *src);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char *str);
int my_show_word_array(char * const *tab);
void *my_memset(void *dst, int c, size_t n);
void *my_calloc(size_t nb_elem, size_t type_size);
char *my_strdup(char const *src);
int handle_wrong_one(int *i, int res, int is_before);
char *my_strconcat(char const *str_a, char const *str_b);
char *my_stricat(char const *str_a, char const *str_b, char const *str_c);
void my_fputstr(int fd, char const *str);
char *my_str_replace(char *str, char *to_replace, char *replacing);
int my_str_isalphanumeric(char const *str);
int my_char_isalphanumeric(char c);
int my_printf(const char *format, ...);
double my_get_double(char const *str);
char **str_to_tab(char *str, char c);
char *my_strdup_to_ch(char *str, char end);

#endif /* !MY_H_ */
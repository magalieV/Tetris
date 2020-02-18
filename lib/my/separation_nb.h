/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** SEPARATION_NB
*/

#ifndef NB
#define NB

int flag_str_sort(va_list, char, between_t);
int flag_strstr_sort(va_list, char, between_t);
int flag_signed_sort(va_list, char, between_t);
int flag_unsigned_sort(va_list, char, between_t);
int flag_unsigned_sort_long(va_list, char, between_t);

typedef struct separ {
    char flag;
    int (*sort_2)(va_list, char, between_t);
} separ_t;

const separ_t SEPARATION_NB[] = {
    {'d', &flag_signed_sort},
    {'i', &flag_signed_sort},
    {'o', &flag_unsigned_sort},
    {'p', &flag_unsigned_sort_long},
    {'x', &flag_unsigned_sort},
    {'X', &flag_unsigned_sort},
    {'u', &flag_unsigned_sort},
    {'b', &flag_unsigned_sort},
    {'S', &flag_strstr_sort},
    {'s', &flag_strstr_sort},
    {'c', &flag_str_sort},
    {'\0', NULL}};

#endif

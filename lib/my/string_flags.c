/*
** EPITECH PROJECT, 2018
** string flags
** File description:
** string flags
*/

#include "printf_hd.h"

int found_attribut(char c)
{
    char *attribut = "#.0123456789";

    for (int i = 0; attribut[i]; i++) {
        if (attribut[i] == c)
            return (1);
    }
    return (0);
}

int flag_str_sort(va_list list, char flag, between_t assign)
{
    char c;
    int nb = 0;
    int bol = 0;

    c = va_arg(list, int);
    for (int k = 0; assign.str[k]; k++) {
        if (assign.str[k] >= '1' && assign.str[k] <= '9' && bol == 0
        && found_flag_point(assign, k) == 0) {
            attribut_space(assign, 1, ' ', k);
            bol = 1;
        }
        if (found_attribut(assign.str[k]) == 0)
            return (84);
    }
    my_putchar(c);
    return (0);
}

int flag_strstr_sort(va_list list, char flag, between_t assign)
{
    char *str;

    str = va_arg(list, char *);
    if (flag == 'S')
        non_printable_string(str);
    else if (flag == 's')
        sort_sring_attribut(str, assign);
    return (1);
}

int non_printable_string(char *str_2)
{
    if (!str_2) {
        my_putstr("(null)");
        return (0);
    }
    for (int i = 0; str_2[i]; i++) {
        if (ind_reco(str_2, &i) == 3)
            return (0);
    }
    return (84);
}

void attribut_space_u(between_t assign, unsigned size, char symb, int k)
{
    char *temp = assign.str;
    unsigned number = 0;

    for (int j = 0; j != k; j++)
        *(temp++);
    number = my_getnbr(temp) - size;
    for (int i = 0; i < number; i++)
        my_putchar(symb);
}

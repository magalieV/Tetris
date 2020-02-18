/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** assign number
*/

#include "printf_hd.h"

int found_more_less(char *c)
{
    for (int i = 0; c[i]; i++) {
        if (c[i] == '-' || c[i] == '+' || c[i] == '.')
            return (84);
    }
    return (0);
}

void octal_assign(unsigned int number, between_t assign, char flag)
{
    char *assign_poss = "#";
    char *temp = assign.str;
    int size = 0;
    int bol = 0;

    size = size_decim_u(number);
    for (int j = 0; temp[j]; j++) {
        if ((temp[j] == assign_poss[0]) && temp)
            my_putchar('0');
        if (temp[j] >= '1' && temp[j] <= '9' && bol == 0
        && found_more_less(temp) == 0) {
            attribut_space_u(assign, size, ' ', j);
            bol = 1;
        }
    }
    my_putnbr_base(number, 8, 87, 0);
}

int decim_flag_f(between_t assign, int size, int bol_2)
{
    int bol = 0;
    int number = 0;
    int k = 0;

    for (int i = 0; assign.str[i]; i++) {
        if (assign.str[i] == '-' && bol_2 == 0)
            return (1);
        else if (assign.str[i] == '-' && bol_2 == 1)
            bol = 1;
    }
    while (assign.str[k] < '0' && assign.str[k] > '9')
        k++;
    if (bol == 1 && bol_2 == 1) {
        get_nbr(assign, &k);
        attribut_space(assign, size, ' ', k);
    }
    return (0);
}

void decim_assign(int number, between_t assign)
{
    line_t line;

    line.recup = 0;
    line.size = size_decim(number);
    line.bol = 0;
    put_space(assign);
    for (int k = 0; assign.str[k]; k++) {
        if (assign.str[k] == '.' || assign.str[k] == '0' && line.bol == 0
        && found_flag_less(assign, k) == 0) {
            line.recup = get_nbr(assign, &k);
            decim_recup(line.recup, k, line.size, assign);
            line.bol = 1;
        } else if (assign.str[k] >= '1' && assign.str[k] <= '9' && line.bol == 0
        && decim_flag_f(assign, line.size, 0) == 0) {
            attribut_space(assign, line.size, ' ', k);
            line.bol = 1;
        }
    }
    my_put_nbr_spe(number, assign, line.recup);
    decim_flag_f(assign, line.size, 1);
}

void hexa_assign(unsigned int number, between_t assign, char flag)
{
    char *temp = assign.str;
    char *doub_tab[] = {"0X", "0x", 0};
    int bol = 0;

    if (temp[0] == '#')
        bol = 1;
    if (flag == 'X') {
        if (bol != 0)
            my_putstr(doub_tab[0]);
        my_putnbr_base(number, 16, 55, 0);
    } else {
        if (bol != 0)
            my_putstr(doub_tab[1]);
        my_putnbr_base(number, 16, 87, 0);
    }
}

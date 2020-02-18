/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** NUMBER
*/

#include "printf_hd.h"

int sort_sring_attribut(char *str, between_t assign)
{
    int bol = 0;
    int size = 2;
    int k = 0;
    int bol_2 = 0;

    for (int k = 0; assign.str[k]; k++) {
        if (assign.str[k] >= '1' && assign.str[k] <= '9' && bol == 0
        && found_flag_point(assign, k) == 0) {
            size = my_strlen(str);
            attribut_space(assign, size, ' ', k);
            bol = 1;
        }
        if (assign.str[k + 1] == '.')
            bol_2 = 1;
    }
    if (bol_2 == 0)
        my_putstr(str);
    return (0);
}

void put_zero(int *str, int bol)
{
    int size_2 = 0;

    if (bol == 1) {
        size_2 = my_strlen_nb(str);
        for (int k = size_2; k <= 2; k++)
            my_put_nbr(0);
        }
}

int decim_recup(int recup, int k, int size, between_t assign)
{
    if (recup == 84)
        return (1);
    else if (recup < 80)
        attribut_space(assign, size, '0', k);
    return (0);
}

int size_decim(int number)
{
    int size = 0;
    int copy = number;

    for (size = 0; copy != 0; size++)
        copy /= 10;
    return (size);
}

unsigned int size_decim_u(unsigned int number)
{
    unsigned int size = 0;
    unsigned int copy = number;

    for (size = 0; copy != 0; size++)
        copy /= 10;
    return (size);
}
